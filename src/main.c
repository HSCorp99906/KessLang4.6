#include <stdio.h>
#include <stdlib.h>
#include "../include/Token.h"
#include "../include/Lexer.h"
#include "../include/Parser.h"
#include "../include/AST.h"


int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1], "r");


    char lineBuf[3000];

    tokenlist_t tokenlist;
    init_tokenlist(&tokenlist, 10);

    lexer_t lexer;
    lexer.lineNum = 1;

    while (fgets(lineBuf, 3000, fp)) {
        lexer.source = lineBuf;

        tokenize(&tokenlist, &lexer);

        ++lexer.lineNum;
    }

    lexer.source = "___EOF___;";
    tokenize(&tokenlist, &lexer);

    parser_t parser;
    init_parser(&parser, tokenlist);
    ast_t __ast = parse(&parser);
    free_arguments(&__ast);

    free(__ast.nodes);
    free(tokenlist.tokens); /* De-allocates tokens. */
    fclose(fp);
}
