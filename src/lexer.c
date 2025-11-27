#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "include\lexer.h"

static const char* src;
static int pos = 0;

void init_lexer(const char* input) {
    src = input;
    pos = 0;
}

Token get_next_token() {
    Token token = {0};

    while (src[pos] == ' ') pos++;

    if (src[pos] == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }

    if (src[pos] == '\n') {
        pos++;
        token.type = TOKEN_NEWLINE;
        return token;
    }

    if (isalpha(src[pos])) {
        int i = 0;
        while (isalnum(src[pos])) {
            token.text[i++] = src[pos++];
        }
        token.type = TOKEN_ID;
        return token;
    }

    if (isdigit(src[pos])) {
        int i = 0;
        while (isdigit(src[pos])) {
            token.text[i++] = src[pos++];
        }
        token.type = TOKEN_NUMBER;
        return token;
    }

    if (src[pos] == '=') {
        pos++;
        token.type = TOKEN_ASSIGN;
        strcpy(token.text, "=");
        return token;
    }

    pos++;
    return token;
}
