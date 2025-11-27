#include <stdio.h>
#include <stdlib.h>

#include "include\lexer.h"
#include "include\parser.h"
#include "include\generator.h"

int main() {
    FILE* f = fopen("input.py", "r");
    if (!f) return 1;

    char buffer[2048];
    fread(buffer, 1, sizeof(buffer), f);
    fclose(f);

    init_lexer(buffer);
    ASTNode* root = parse();
    generate_c(root);

    return 0;
}
