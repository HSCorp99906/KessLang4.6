#include "../include/Executer.h"


void execute(ast_t ast) {

    if (ast.pos == 0) {
        printf("\n%s\n", ast.nodes[ast.pos].args[0].value);
    }

    for (int i = 0; i < ast.pos; ++i) {
        printf("%s\n", ast.nodes[i].args[0].value);
    }
}
