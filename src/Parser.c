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
    unsigned int lparenc = 0;
    unsigned int rparenc = 0;

    while (1) {
        if (parser -> currentToken.type == T_EOF) {
            break;
        } else {
            char* __semicolon = strstr(parser -> currentToken.line, ";");

            if (!(__semicolon) && parser -> currentToken.line[strlen(parser -> currentToken.line) - 1] != ';') {

                char pointBuf[256];

                for (int i = 0; i < strlen(parser -> currentToken.line); ++i) {
                    if (i != strlen(parser -> currentToken.line) - 2) {
                        pointBuf[i] = ' ';
                    } else {
                        pointBuf[i] = '^';
                    }
                }

                error = 1;
                printf("\033[91m\nERROR: Missing semicolon. \n\n%s\n%s", parser -> currentToken.line, pointBuf);
                break;
            }
        }

        if (parser -> currentToken.type == T_LPAREN) {
            ++lparenc;
        } else if (parser -> currentToken.type == T_RPAREN) {
            ++rparenc;
        }

        if (parser -> currentToken.character == ';') {
            if (lparenc < rparenc || lparenc > rparenc) {
                printf("\033[91m\nERROR: Unmatched parenthesis. \n\n%s\n", parser -> currentToken.line);
                break;
            }

            lparenc = 0;
            rparenc = 0;
        }

        advance(parser);
    }
}
