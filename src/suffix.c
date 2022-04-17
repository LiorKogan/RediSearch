#include "suffix.h"
#include "rmutil/rm_assert.h"
#include "config.h"
#include <string.h>

typedef void *(*TrieMapReplaceFunc)(void *oldval, void *newval);

typedef struct suffixData {
  //int wordExists; // exact match to string exists already
  rune *rune;
  char *term;             // string is used in the array of all suffix tokens
  arrayof(char *) array;   // list of words containing the string. weak pointers
} suffixData;

#define Suffix_GetData(node) node ? node->payload ? \
                             (suffixData *)node->payload->data : NULL : NULL

void delCb(void *val) {
  suffixData *node = val;
  array_free(node->array);
  if (node->term) {
    rm_free(node->term);
  }
  rm_free(node);
}

static suffixData *createSuffixNode(char *term, int keepPtr) {
  suffixData *node = rm_calloc(1, sizeof(*node));
  if (keepPtr) {
    node->term = term;
  }
  node->array = array_ensure_append_1(node->array, term);
  return node;
}

static void freeSuffixNode(suffixData *node) {
  array_free(node->array);
  rm_free(node->term);
  rm_free(node);
}

void addSuffixTrie(Trie *trie, const char *str, uint32_t len) {
  // size_t rlen = 0;
  // rune *runes = strToRunesN(str, len, &rlen);
  //rune runes[len];
  //size_t rlen = strToRunesN(str, len, runes);
  //rune *runes = strToRunesN(str, len, &rlen);

  size_t rlen = 0;
  runeBuf buf;
  rune *runes = runeBufFill(str, len, &buf, &rlen);

  TrieNode *trienode = TrieNode_Get(trie->root, runes, rlen, 1, NULL);
  suffixData *data = NULL;
  if (trienode && trienode->payload) {
    // suffixData *node = TrieNode_GetValue(trie->root, runes, rlen, 1);
    data = Suffix_GetData(trienode);
    // if string was added in the past, skip
    if (data && data->term) {
      //rm_free(runes);
      runeBufFree(&buf);
      return;
    }
  }

  char *copyStr = rm_strndup(str, len);
  // printf("string %s len %ld rlen %ld\n", str, len, rlen);
  if (!data) {
    data = createSuffixNode(copyStr, 1);
    RSPayload payload = { .data = (char*)data, .len = sizeof(*data) };
    TrieNode_Add(&trie->root, runes, rlen, &payload, 1, ADD_IGNORE);
  } else {
    RS_LOG_ASSERT(!data->term, "can't reach here");
    data->term = copyStr;
    data->array = array_ensure_append_1(data->array, copyStr);
  }

  // Save string copy to all suffixes of it
  // If it exists, move to the next field
  for (int j = 1; j < len - MIN_SUFFIX + 1; ++j) {
    TrieNode *trienode = TrieNode_Get(trie->root, runes + j, rlen - j, 1, NULL);
    
    data = Suffix_GetData(trienode);
    //void *payload = trienode ? trienode->payload : NULL;
    size_t len;
    // printf("%s %p %p %p\n", runesToStr(runes + j, rlen - j, &len), trienode, payload, node);
    if (!trienode || !trienode->payload) {
      data = createSuffixNode(copyStr, 0);
      RSPayload payload = { .data = (char*)data, .len = sizeof(*data) };
      TrieNode_Add(&trie->root, runes + j, rlen - j, &payload, 1, ADD_IGNORE);
    } else {
      data->array = array_ensure_append_1(data->array, copyStr);
    }
  }
  runeBufFree(&buf);
}

static void removeSuffix(const char *str, size_t rlen, arrayof(char*) array) {
  for (int i = 0; i < array_len(array); ++i) {
    if (!strncmp(array[i], str, rlen)) {
      array_del_fast(array, i);
      return;
    }
  }
}

void deleteSuffixTrie(Trie *trie, const char *str, uint32_t len) {
  size_t rlen = 0;
  //rune *runes = strToRunesN(str, len, &rlen);

  runeBuf buf;
  rune *runes = runeBufFill(str, len, &buf, &rlen);

  //rune runes[len];
  //size_t rlen = strToRunesN(str, len, &runes);
  char *oldTerm = NULL;

  // iterate all matching terms and remove word
  for (int j = 0; j < len; ++j) {
    suffixData *node = TrieNode_GetValue(trie->root, runes + j, rlen - j, 1);
    // suffixData *node = TrieMap_Find(trie, str + j, len - j);
    if (j == 0) {
      // keep pointer to word string to free after it was found in al sub tokens.
      oldTerm = node->term;
      node->term = NULL;
    }
    // remove from array
    removeSuffix(str, len, node->array);
    // if array is empty, remove the node
    if (array_len(node->array) == 0) {
      RS_LOG_ASSERT(!node->term, "array should contain a pointer to the string");
      TrieNode_Delete(trie->root, runes + j, rlen - j);
      freeSuffixNode(node);
    }
  }
  rm_free(oldTerm);
  runeBufFree(&buf);
}

static int processSuffixData(suffixData *data, TrieSuffixCallback callback, void *ctx) {
  if (!data) {
    return REDISMODULE_OK;
  }
  arrayof(char *) array = data->array;
  for (int i = 0; i < array_len(array); ++i) {
    if (callback(array[i], strlen(array[i]), ctx) != REDISMODULE_OK) {
      return REDISEARCH_ERR;
    }
  }
  return REDISMODULE_OK;
}

static int recursiveAdd(TrieNode *node, TrieSuffixCallback callback, void *ctx) {
  if (node->payload) {
    size_t rlen;
    // printf("nodestr %s len %d rlen %ld", runesToStr(node->str, node->len, &rlen), node->len, rlen);
    suffixData *data = Suffix_GetData(node);
    processSuffixData(data, callback, ctx);
  }
  if (node->numChildren) {
    TrieNode **children = __trieNode_children(node);
    for (int i = 0; i < node->numChildren; ++i) {
      // printf("child %d ", i);
      if (recursiveAdd(children[i], callback, ctx) != REDISMODULE_OK) {
        return REDISMODULE_ERR;
      }
    }
  }
  return REDISMODULE_OK;
}

void Suffix_IterateContains(TrieNode *n, const rune *str, size_t nstr, bool prefix,
                            TrieSuffixCallback callback, void *ctx) {
  if (prefix) {
    // get string from node and children
    TrieNode *node = TrieNode_Get(n, str, nstr, 0, NULL);
    if (!node) {
      return;
    }
    recursiveAdd(node, callback, ctx);
  } else {
    // exact match. Get strings from a single node
    suffixData *data = TrieNode_GetValue(n, str, nstr, 1);
    if (data) {
      processSuffixData(data, callback, ctx);
    }
  }                              
}
