#ifndef KESS_LEXER_H_
#define KESS_LEXER_H_

#include "Token.h"
#include <string.h>
#include <stdio.h>


typedef struct Lexer {
    char* source;
    unsigned int lineNum;

} lexer_t;


void tokenize(tokenlist_t* tokenlist, lexer_t* lexer);


#endif
