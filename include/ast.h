#ifndef AST_H
#define AST_H

typedef enum {
    AST_ASSIGNMENT,
    AST_LITERAL,
    AST_IDENTIFIER
} ASTType;

typedef struct ASTNode {
    ASTType type;
    char value[64];
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* new_node(ASTType type, const char* val);
ASTNode* new_binary(ASTType type, ASTNode* l, ASTNode* r);

#endif