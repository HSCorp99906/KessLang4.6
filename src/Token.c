#include "../include/Token.h"


void init_tokenlist(tokenlist_t* tokenlist, size_t size) {
    tokenlist -> pos = 0;
    tokenlist -> tokens = (token_t*)malloc(sizeof(struct Token) * size);
    tokenlist -> size = size;
}


void add_token(tokenlist_t* tokenlist, token_t element) {
    tokenlist -> size += 6;
    tokenlist -> tokens = realloc(tokenlist -> tokens, tokenlist -> size);
    tokenlist -> tokens[tokenlist -> pos] = element;
    ++tokenlist -> pos;
}
