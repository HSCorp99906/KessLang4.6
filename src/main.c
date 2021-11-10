#include <stdio.h>
#include <stdlib.h>
#include "../include/Token.h"


int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1], "r");


    char lineBuf[3000];

    while (fgets(lineBuf, 3000, fp)) {
        printf("%s\n", lineBuf);
    }

    tokenlist_t tokenlist;
    init_tokenlist(&tokenlist, 10); /* 10 bytes on heap. */

    free(tokenlist.tokens); /* De-allocates tokens. */
    fclose(fp);
}
