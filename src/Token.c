#include "../include/Token.h"


void init_tokenlist(tokenlist_t* tokenlist, size_t size) {
    tokenlist -> pos = 0;
    tokenlist -> tokens = (token_t*)malloc(sizeof(struct Token) * size);
    tokenlist -> size = size;
}


void add_token(tokenlist_t* tokenlist, token_t element) {
    tokenlist -> size += 6;
    tokenlist -> tokens = realloc(tokenlist -> tokens, sizeof(struct Token) * tokenlist -> size);
    tokenlist -> tokens[tokenlist -> pos] = element;
    ++tokenlist -> pos;
}

token_t create_token(tt_t type, char character, char* line, unsigned int lineNum) {
    token_t token;
    token.type = type;
    token.character = character;
    token.line = line;
    token.lineNumber = lineNum;
    return token;
}
