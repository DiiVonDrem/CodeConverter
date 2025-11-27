#include "include\parser.h"
#include "include\lexer.h"
#include <string.h>

static Token current;

static void advance() {
    current = get_next_token();
}

ASTNode* parse_assignment() {
    char name[64];
    strcpy(name, current.text);

    advance(); // ID
    advance(); // '='

    char val[64];
    strcpy(val, current.text);

    advance(); // NUMBER

    return new_binary(
        AST_ASSIGNMENT,
        new_node(AST_IDENTIFIER, name),
        new_node(AST_LITERAL, val)
    );
}

ASTNode* parse() {
    advance();
    if (current.type == TOKEN_ID) {
        return parse_assignment();
    }
    return NULL;
}
