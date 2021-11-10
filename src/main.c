#include <stdio.h>
#include <stdlib.h>
#include "../include/Token.h"
#include "../include/Lexer.h"


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

    free(tokenlist.tokens); /* De-allocates tokens. */
    fclose(fp);
}
