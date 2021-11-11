#ifndef KESS_PARSER_H_
#define KESS_PARSER_H_

#include "Token.h"
#include "AST.h"
#include <string.h>
#include <stdio.h>

typedef struct Parser {
    tokenlist_t tokenTray;
    token_t currentToken;
    unsigned int pos;
} parser_t;


void init_parser(parser_t* parser, tokenlist_t tokenlist);
void parse(parser_t* parser);


#endif
