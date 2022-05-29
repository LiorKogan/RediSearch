
/* #line 1 "lexer.rl" */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "../parse.h"
#include "parser.h"
#include "../../query_node.h"
#include "../../stopwords.h"

/* forward declarations of stuff generated by lemon */

#define RSQuery_Parse_v1 RSQueryParser_v1_ // weird Lemon quirk.. oh well..
#define RSQuery_ParseAlloc_v1 RSQueryParser_v1_Alloc
#define RSQuery_ParseFree_v1 RSQueryParser_v1_Free

void RSQuery_Parse_v1(void *yyp, int yymajor, QueryToken yyminor, QueryParseCtx *ctx);
void *RSQuery_ParseAlloc_v1(void *(*mallocProc)(size_t));
void RSQuery_ParseFree_v1(void *p, void (*freeProc)(void *));


/* #line 264 "lexer.rl" */



/* #line 30 "lexer.c" */
static const char _query_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	12, 1, 13, 1, 14, 1, 15, 1, 
	16, 1, 17, 1, 18, 1, 19, 1, 
	20, 1, 21, 1, 22, 1, 23, 1, 
	24, 1, 25, 1, 26, 1, 27, 1, 
	28, 1, 29, 1, 30, 1, 31, 1, 
	32, 1, 33, 1, 34, 1, 35, 1, 
	36, 1, 37, 1, 38, 1, 39, 1, 
	40, 2, 2, 3, 2, 2, 4, 2, 
	2, 5, 2, 2, 6, 2, 2, 7, 
	2, 2, 8, 2, 2, 9, 2, 2, 
	10, 2, 2, 11
};

static const short _query_key_offsets[] = {
	0, 10, 20, 21, 22, 32, 34, 36, 
	39, 41, 43, 46, 48, 58, 96, 107, 
	117, 118, 131, 142, 148, 153, 156, 172, 
	184, 187, 193, 198, 201, 217, 231, 244, 
	245, 255, 265, 277
};

static const char _query_trans_keys[] = {
	9, 13, 32, 47, 58, 64, 91, 96, 
	123, 126, 9, 13, 32, 47, 58, 64, 
	91, 96, 123, 126, 110, 102, 9, 13, 
	32, 47, 58, 64, 91, 96, 123, 126, 
	48, 57, 48, 57, 45, 48, 57, 48, 
	57, 48, 57, 45, 48, 57, 48, 57, 
	9, 13, 32, 47, 58, 64, 91, 96, 
	123, 126, 32, 34, 36, 37, 39, 40, 
	41, 42, 43, 45, 58, 59, 61, 64, 
	91, 92, 93, 95, 105, 123, 124, 125, 
	126, 127, 0, 8, 9, 13, 14, 31, 
	33, 47, 48, 57, 60, 63, 94, 96, 
	42, 92, 96, 0, 47, 58, 64, 91, 
	94, 123, 127, 92, 96, 0, 47, 58, 
	64, 91, 94, 123, 127, 105, 45, 92, 
	96, 0, 47, 48, 57, 58, 64, 91, 
	94, 123, 127, 42, 92, 96, 0, 47, 
	58, 64, 91, 94, 123, 127, 42, 46, 
	69, 101, 48, 57, 42, 69, 101, 48, 
	57, 42, 48, 57, 42, 46, 69, 92, 
	96, 101, 0, 47, 48, 57, 58, 64, 
	91, 94, 123, 127, 42, 45, 92, 96, 
	0, 47, 58, 64, 91, 94, 123, 127, 
	105, 48, 57, 42, 46, 69, 101, 48, 
	57, 42, 69, 101, 48, 57, 42, 48, 
	57, 42, 46, 69, 92, 96, 101, 0, 
	47, 48, 57, 58, 64, 91, 94, 123, 
	127, 42, 45, 92, 96, 0, 47, 48, 
	57, 58, 64, 91, 94, 123, 127, 42, 
	92, 96, 0, 47, 48, 57, 58, 64, 
	91, 94, 123, 127, 62, 92, 96, 0, 
	47, 58, 64, 91, 94, 123, 127, 9, 
	13, 32, 47, 58, 64, 91, 96, 123, 
	126, 42, 92, 96, 110, 0, 47, 58, 
	64, 91, 94, 123, 127, 42, 92, 96, 
	102, 0, 47, 58, 64, 91, 94, 123, 
	127, 0
};

static const char _query_single_lengths[] = {
	0, 0, 1, 1, 0, 0, 0, 1, 
	0, 0, 1, 0, 0, 24, 3, 2, 
	1, 3, 3, 4, 3, 1, 6, 4, 
	1, 4, 3, 1, 6, 4, 3, 1, 
	2, 0, 4, 4
};

static const char _query_range_lengths[] = {
	5, 5, 0, 0, 5, 1, 1, 1, 
	1, 1, 1, 1, 5, 7, 4, 4, 
	0, 5, 4, 1, 1, 1, 5, 4, 
	1, 1, 1, 1, 5, 5, 5, 0, 
	4, 5, 4, 4
};

static const unsigned char _query_index_offsets[] = {
	0, 6, 12, 14, 16, 22, 24, 26, 
	29, 31, 33, 36, 38, 44, 76, 84, 
	91, 93, 102, 110, 116, 121, 124, 136, 
	145, 148, 154, 159, 162, 174, 184, 193, 
	195, 202, 208, 217
};

static const char _query_indicies[] = {
	1, 1, 1, 1, 1, 0, 2, 2, 
	2, 2, 2, 0, 3, 0, 4, 0, 
	5, 5, 5, 5, 5, 0, 7, 6, 
	9, 8, 10, 11, 8, 11, 8, 13, 
	12, 14, 15, 12, 15, 0, 16, 16, 
	16, 16, 16, 0, 18, 20, 21, 22, 
	23, 24, 25, 26, 23, 27, 29, 30, 
	31, 32, 33, 34, 35, 36, 37, 38, 
	39, 40, 41, 17, 17, 18, 17, 19, 
	28, 19, 19, 1, 42, 43, 0, 0, 
	0, 0, 0, 1, 44, 0, 0, 0, 
	0, 0, 2, 46, 45, 48, 50, 47, 
	47, 49, 47, 47, 47, 5, 52, 50, 
	51, 51, 51, 51, 51, 5, 52, 53, 
	54, 54, 7, 51, 52, 54, 54, 9, 
	51, 52, 11, 51, 52, 53, 55, 50, 
	51, 55, 51, 49, 51, 51, 51, 5, 
	52, 10, 50, 51, 51, 51, 51, 51, 
	5, 46, 57, 56, 42, 59, 60, 60, 
	57, 58, 42, 60, 60, 13, 58, 42, 
	15, 58, 42, 59, 61, 43, 58, 61, 
	58, 28, 58, 58, 58, 1, 42, 14, 
	43, 62, 62, 63, 62, 62, 62, 1, 
	42, 43, 58, 58, 63, 58, 58, 58, 
	1, 64, 45, 65, 0, 0, 0, 0, 
	0, 16, 1, 1, 1, 1, 1, 45, 
	42, 43, 62, 66, 62, 62, 62, 62, 
	1, 42, 43, 62, 67, 62, 62, 62, 
	62, 1, 0
};

static const char _query_trans_targs[] = {
	13, 14, 15, 3, 13, 18, 13, 19, 
	13, 20, 8, 21, 13, 26, 11, 27, 
	32, 13, 13, 13, 13, 15, 13, 16, 
	13, 13, 17, 24, 28, 13, 13, 31, 
	32, 13, 33, 13, 14, 34, 13, 13, 
	13, 13, 13, 0, 1, 13, 2, 13, 
	5, 22, 4, 13, 13, 6, 7, 23, 
	13, 25, 13, 9, 10, 29, 13, 30, 
	13, 12, 35, 14
};

static const char _query_trans_actions[] = {
	63, 86, 71, 0, 9, 89, 59, 5, 
	61, 5, 0, 0, 57, 65, 0, 0, 
	68, 39, 35, 37, 11, 83, 29, 83, 
	15, 17, 80, 77, 65, 23, 25, 0, 
	83, 31, 0, 33, 83, 86, 19, 13, 
	21, 27, 41, 0, 0, 51, 0, 49, 
	0, 89, 0, 55, 43, 0, 0, 89, 
	47, 65, 45, 0, 0, 86, 53, 65, 
	7, 0, 86, 74
};

static const char _query_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const char _query_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const unsigned char _query_eof_trans[] = {
	1, 1, 1, 1, 1, 7, 9, 9, 
	9, 13, 13, 1, 1, 0, 1, 1, 
	46, 48, 52, 52, 52, 52, 52, 52, 
	57, 59, 59, 59, 59, 63, 59, 46, 
	1, 46, 63, 63
};

static const int query_start = 13;
static const int query_first_final = 13;
static const int query_error = -1;

static const int query_en_main = 13;


/* #line 267 "lexer.rl" */

QueryNode *RSQuery_ParseRaw_v1(QueryParseCtx *q) {
  void *pParser = RSQuery_ParseAlloc_v1(rm_malloc);

  
  int cs, act;
  const char* ts = q->raw;
  const char* te = q->raw + q->len;
  
/* #line 215 "lexer.c" */
	{
	cs = query_start;
	ts = 0;
	te = 0;
	act = 0;
	}

/* #line 276 "lexer.rl" */
  QueryToken tok = {.len = 0, .pos = 0, .s = 0};
  
  //parseCtx ctx = {.root = NULL, .ok = 1, .errorMsg = NULL, .q = q};
  const char* p = q->raw;
  const char* pe = q->raw + q->len;
  const char* eof = pe;
  
  
/* #line 232 "lexer.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
_resume:
	_acts = _query_actions + _query_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
/* #line 1 "NONE" */
	{ts = p;}
	break;
/* #line 251 "lexer.c" */
		}
	}

	_keys = _query_trans_keys + _query_key_offsets[cs];
	_trans = _query_index_offsets[cs];

	_klen = _query_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _query_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _query_indicies[_trans];
_eof_trans:
	cs = _query_trans_targs[_trans];

	if ( _query_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _query_actions + _query_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 2:
/* #line 1 "NONE" */
	{te = p+1;}
	break;
	case 3:
/* #line 55 "lexer.rl" */
	{act = 1;}
	break;
	case 4:
/* #line 67 "lexer.rl" */
	{act = 2;}
	break;
	case 5:
/* #line 76 "lexer.rl" */
	{act = 3;}
	break;
	case 6:
/* #line 94 "lexer.rl" */
	{act = 5;}
	break;
	case 7:
/* #line 163 "lexer.rl" */
	{act = 14;}
	break;
	case 8:
/* #line 177 "lexer.rl" */
	{act = 16;}
	break;
	case 9:
/* #line 206 "lexer.rl" */
	{act = 21;}
	break;
	case 10:
/* #line 209 "lexer.rl" */
	{act = 23;}
	break;
	case 11:
/* #line 235 "lexer.rl" */
	{act = 25;}
	break;
	case 12:
/* #line 85 "lexer.rl" */
	{te = p+1;{
    tok.pos = ts-q->raw;
    tok.len = te - ts;
    tok.s = ts+1;
    RSQuery_Parse_v1(pParser, ARROW, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 13:
/* #line 94 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    tok.s = ts;
    tok.len = te-ts;
    tok.numval = *ts == '-' ? -INFINITY : INFINITY;
    RSQuery_Parse_v1(pParser, NUMBER, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 14:
/* #line 105 "lexer.rl" */
	{te = p+1;{
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, QUOTE, tok, q);  
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 15:
/* #line 112 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, OR, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 16:
/* #line 119 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, LP, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 17:
/* #line 127 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, RP, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 18:
/* #line 134 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, LB, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 19:
/* #line 141 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, RB, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 20:
/* #line 148 "lexer.rl" */
	{te = p+1;{ 
     tok.pos = ts-q->raw;
     RSQuery_Parse_v1(pParser, COLON, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
   }}
	break;
	case 21:
/* #line 155 "lexer.rl" */
	{te = p+1;{ 
     tok.pos = ts-q->raw;
     RSQuery_Parse_v1(pParser, SEMICOLON, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
   }}
	break;
	case 22:
/* #line 170 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, TILDE, tok, q);  
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 23:
/* #line 184 "lexer.rl" */
	{te = p+1;{
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, PERCENT, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 24:
/* #line 191 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, LSQB, tok, q);  
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }  
  }}
	break;
	case 25:
/* #line 198 "lexer.rl" */
	{te = p+1;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, RSQB, tok, q);   
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    } 
  }}
	break;
	case 26:
/* #line 205 "lexer.rl" */
	{te = p+1;}
	break;
	case 27:
/* #line 206 "lexer.rl" */
	{te = p+1;}
	break;
	case 28:
/* #line 207 "lexer.rl" */
	{te = p+1;}
	break;
	case 29:
/* #line 223 "lexer.rl" */
	{te = p+1;{
    tok.len = te-ts - 1;
    tok.s = ts;
    tok.numval = 0;
    tok.pos = ts-q->raw;
    
    RSQuery_Parse_v1(pParser, PREFIX, tok, q);
    
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 30:
/* #line 248 "lexer.rl" */
	{te = p+1;{
    int is_attr = (*(ts+1) == '$') ? 1 : 0;
    tok.type = is_attr ? QT_PARAM_TERM : QT_TERM;
    tok.len = te - (ts + 2 + is_attr);
    tok.s = ts + 1 + is_attr;
    tok.numval = 0;
    tok.pos = ts-q->raw;

    RSQuery_Parse_v1(pParser, CONTAINS, tok, q);
    
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 31:
/* #line 55 "lexer.rl" */
	{te = p;p--;{ 
    tok.s = ts;
    tok.len = te-ts;
    char *ne = (char*)te;
    tok.numval = strtod(tok.s, &ne);
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, NUMBER, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
    
  }}
	break;
	case 32:
/* #line 163 "lexer.rl" */
	{te = p;p--;{ 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, MINUS, tok, q);  
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 33:
/* #line 177 "lexer.rl" */
	{te = p;p--;{
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, STAR, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 34:
/* #line 206 "lexer.rl" */
	{te = p;p--;}
	break;
	case 35:
/* #line 209 "lexer.rl" */
	{te = p;p--;{
    tok.len = te-ts;
    tok.s = ts;
    tok.numval = 0;
    tok.pos = ts-q->raw;
    if (!StopWordList_Contains(q->opts->stopwords, tok.s, tok.len)) {
      RSQuery_Parse_v1(pParser, TERM, tok, q);
    } else {
      RSQuery_Parse_v1(pParser, STOPWORD, tok, q);
    }
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 36:
/* #line 235 "lexer.rl" */
	{te = p;p--;{
    int is_attr = (*(ts+1) == '$') ? 1 : 0;
    tok.type = is_attr ? QT_PARAM_TERM : QT_TERM;
    tok.len = te - (ts + 1 + is_attr);
    tok.s = ts + 1 + is_attr;
    tok.numval = 0;
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, SUFFIX, tok, q);
    
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 37:
/* #line 55 "lexer.rl" */
	{{p = ((te))-1;}{ 
    tok.s = ts;
    tok.len = te-ts;
    char *ne = (char*)te;
    tok.numval = strtod(tok.s, &ne);
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, NUMBER, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
    
  }}
	break;
	case 38:
/* #line 177 "lexer.rl" */
	{{p = ((te))-1;}{
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, STAR, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 39:
/* #line 235 "lexer.rl" */
	{{p = ((te))-1;}{
    int is_attr = (*(ts+1) == '$') ? 1 : 0;
    tok.type = is_attr ? QT_PARAM_TERM : QT_TERM;
    tok.len = te - (ts + 1 + is_attr);
    tok.s = ts + 1 + is_attr;
    tok.numval = 0;
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, SUFFIX, tok, q);
    
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }}
	break;
	case 40:
/* #line 1 "NONE" */
	{	switch( act ) {
	case 1:
	{{p = ((te))-1;} 
    tok.s = ts;
    tok.len = te-ts;
    char *ne = (char*)te;
    tok.numval = strtod(tok.s, &ne);
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, NUMBER, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
    
  }
	break;
	case 2:
	{{p = ((te))-1;}
    tok.pos = ts-q->raw;
    tok.len = te - (ts + 1);
    tok.s = ts+1;
    RSQuery_Parse_v1(pParser, MODIFIER, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }
	break;
	case 3:
	{{p = ((te))-1;}
    tok.pos = ts-q->raw;
    tok.len = te - (ts + 1);
    tok.s = ts+1;
    RSQuery_Parse_v1(pParser, ATTRIBUTE, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }
	break;
	case 5:
	{{p = ((te))-1;} 
    tok.pos = ts-q->raw;
    tok.s = ts;
    tok.len = te-ts;
    tok.numval = *ts == '-' ? -INFINITY : INFINITY;
    RSQuery_Parse_v1(pParser, NUMBER, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }
	break;
	case 14:
	{{p = ((te))-1;} 
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, MINUS, tok, q);  
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }
	break;
	case 16:
	{{p = ((te))-1;}
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, STAR, tok, q);
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }
	break;
	case 23:
	{{p = ((te))-1;}
    tok.len = te-ts;
    tok.s = ts;
    tok.numval = 0;
    tok.pos = ts-q->raw;
    if (!StopWordList_Contains(q->opts->stopwords, tok.s, tok.len)) {
      RSQuery_Parse_v1(pParser, TERM, tok, q);
    } else {
      RSQuery_Parse_v1(pParser, STOPWORD, tok, q);
    }
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }
	break;
	case 25:
	{{p = ((te))-1;}
    int is_attr = (*(ts+1) == '$') ? 1 : 0;
    tok.type = is_attr ? QT_PARAM_TERM : QT_TERM;
    tok.len = te - (ts + 1 + is_attr);
    tok.s = ts + 1 + is_attr;
    tok.numval = 0;
    tok.pos = ts-q->raw;
    RSQuery_Parse_v1(pParser, SUFFIX, tok, q);
    
    if (!QPCTX_ISOK(q)) {
      {p++; goto _out; }
    }
  }
	break;
	default:
	{{p = ((te))-1;}}
	break;
	}
	}
	break;
/* #line 765 "lexer.c" */
		}
	}

_again:
	_acts = _query_actions + _query_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 0:
/* #line 1 "NONE" */
	{ts = 0;}
	break;
/* #line 778 "lexer.c" */
		}
	}

	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _query_eof_trans[cs] > 0 ) {
		_trans = _query_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

/* #line 284 "lexer.rl" */
  
  if (QPCTX_ISOK(q)) {
    RSQuery_Parse_v1(pParser, 0, tok, q);
  }
  RSQuery_ParseFree_v1(pParser, rm_free);
  if (!QPCTX_ISOK(q) && q->root) {
    QueryNode_Free(q->root);
    q->root = NULL;
  }
  return q->root;
}

