#include <stdlib.h>
#include <string.h>
#include "include\ast.h"

ASTNode* new_node(ASTType type, const char* val) {
    ASTNode* n = malloc(sizeof(ASTNode));
    n->type = type;
    strcpy(n->value, val);
    n->left = n->right = NULL;
    return n;
}

ASTNode* new_binary(ASTType type, ASTNode* l, ASTNode* r) {
    ASTNode* n = malloc(sizeof(ASTNode));
    n->type = type;
    n->left = l;
    n->right = r;
    return n;
}
