#ifndef KESS_TOKEN_H_
#define KESS_TOKEN_H_

#include <stdlib.h>


typedef enum TokenTypes {
    T_CHAR,
    T_INTEGER,
} tt_t;


typedef struct Token {
    tt_t type;
    char character;
    char* line;
    unsigned int lineNumber;
} token_t;


typedef struct TokenList {
    token_t* tokens;
    size_t size;
    unsigned int pos;
} tokenlist_t;


void init_tokenlist(tokenlist_t* tokenlist, size_t size);
void add_token(tokenlist_t* tokenlist, token_t element);
token_t create_token(tt_t type, char character, char* line, unsigned int lineNum);

#endif
