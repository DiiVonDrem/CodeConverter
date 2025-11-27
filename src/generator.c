#include <stdio.h>
#include "include\generator.h"

void generate_c(ASTNode* root) {
    printf("#include <stdio.h>\n\nint main() {\n");

    if (root->type == AST_ASSIGNMENT) {
        printf("    int %s = %s;\n",
               root->left->value,
               root->right->value);
    }

    printf("    return 0;\n}\n");
}
