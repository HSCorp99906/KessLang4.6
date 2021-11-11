#ifndef KESS_AST_H_
#define KESS_AST_H_

#include <stdlib.h>
#include "Token.h"

typedef enum ExpressionTypes {
    CALL_EXPRESSION,
} ast_e_types_t;


typedef enum Property {
    IDENTIFIER,
} property_t;

typedef enum ArgumentTypes {
    LITERAL,
    NAME
} argument_tt;


typedef struct Argument {
    argument_tt type;
    char* value;
} argument_t;


typedef struct AST_NODE {
    ast_e_types_t type;
    property_t property;
    char* id;
    argument_t* args;

} ast_node_t;


typedef struct KESS_AST {
    unsigned int treesize;
    ast_node_t* nodes;
    char* type;
    unsigned short int parseSuccess;

} ast_t;


#endif
