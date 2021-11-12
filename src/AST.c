#include "../include/AST.h"


void free_nodes(ast_t* ast) {
    for (int i = 0; i < ast -> treesize; ++i) {
        free(ast -> nodes[i].args);
        ast -> nodes[i].args = NULL;
    }

    free(ast -> nodes);
}
