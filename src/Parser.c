#include "../include/Parser.h"

void init_parser(parser_t* parser, tokenlist_t tokenlist) {
    parser -> tokenTray = tokenlist;
    parser -> pos = 0;
    parser -> currentToken = *parser -> tokenTray.tokens;
}


void advance(parser_t* parser) {
    ++parser -> pos;
    parser -> currentToken = parser -> tokenTray.tokens[parser -> pos];
}


void parse(parser_t* parser) {
    typedef unsigned short int bool_t;
    bool_t error = 0;

    while (1) {
        if (parser -> currentToken.type == T_EOF) {
            break;
        } else {
            char* __semicolon = strstr(parser -> currentToken.line, ";");

            if (!(__semicolon) && parser -> currentToken.line[strlen(parser -> currentToken.line) - 1] != ';') {
                error = 1;
                printf("ERROR: Missing semicolon on line %d.\n", parser -> currentToken.lineNumber);
                break;
            }
        }

        advance(parser);
    }
}
