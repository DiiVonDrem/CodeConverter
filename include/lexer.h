#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_ID,
    TOKEN_NUMBER,
    TOKEN_ASSIGN,
    TOKEN_NEWLINE,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char text[64];
} Token;

Token get_next_token();

void init_lexer(const char* input);

#endif