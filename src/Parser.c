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


ast_t parse(parser_t* parser) {
    typedef unsigned short int bool_t;
    bool_t error = 0;
    unsigned int lparenc = 0;
    unsigned int rparenc = 0;

    bool_t quote = 0;

    ast_t __ast;
    __ast.treesize = 10;
    __ast.nodes = (ast_node_t*)malloc(sizeof(ast_node_t) * __ast.treesize);
    __ast.type = "Program.";
    __ast.pos = 0;
    __ast.nodes[__ast.pos].args = (argument_t*)malloc(sizeof(argument_t) * __ast.treesize);


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
                printf("\033[91m\nERROR: Missing semicolon. \n\n%s\n%s\n\n", parser -> currentToken.line, pointBuf);
                break;
            }
        }

        if (parser -> currentToken.type == T_LPAREN) {
            ++lparenc;
        } else if (parser -> currentToken.type == T_RPAREN) {

            if (lparenc < 1) {
                printf("\033[91m\nERROR: Syntax error. \n\n%s\n\n", parser -> currentToken.line);
                break;
            }

            ++rparenc;
        }

        if (parser -> currentToken.type == T_QUOTE) {
            quote = 1;
        }

        if (parser -> currentToken.character == ';') {
            if (lparenc < rparenc || lparenc > rparenc) {
                printf("\033[91m\nERROR: Unmatched parenthesis. \n\n%s\n\n", parser -> currentToken.line);
                break;
            }

            lparenc = 0;
            rparenc = 0;
            quote = 0;
        }

        if (lparenc > 0 && rparenc > 0) {
            /* This will have to be changed later
            *  Due to the abiliy to create functions.
            */

            char nameBuf[500];
            char argBuf[500];
            unsigned int argBufi = 0;

            memset(nameBuf, 0, 500);
            memset(argBuf, 0, 500);

            for (int i = 0; i < strlen(parser -> currentToken.line) && i < 500; ++i) {
                if (parser -> currentToken.line[i] == '(') {
                    break;
                }

                strncat(nameBuf, &parser -> currentToken.line[i], 1);
            }

            for (int i = strlen(nameBuf) + 2; i < strlen(parser -> currentToken.line); ++i) {
                if (parser -> currentToken.line[i] == '"' || parser -> currentToken.line[i] == ')') {
                    break;
                }

                argBuf[argBufi] = parser -> currentToken.line[i];
                ++argBufi;
            }

            __ast.nodes[__ast.pos].args[0].value = argBuf;
        }

        advance(parser);
    }

    return __ast;
}
