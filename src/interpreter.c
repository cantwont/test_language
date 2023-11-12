#include "../include/interpreter.h"
#include <stdio.h>

int evaluate(ASTNode* node) {
    if (node == NULL) {
        return 0;
    }

    switch (node->type) {
        case NODE_NUMBER:
            return node->value;
        case NODE_ADDITION:
            return evaluate(node->left) + evaluate(node->right);
        case NODE_SUBTRACTION:
            return evaluate(node->left) - evaluate(node->right);
        default:
            return 0;
    }
}

void interpret(ASTNode* ast, char buffer[]) {
    if (ast != NULL) {
        int result = evaluate(ast);
        sprintf(buffer, "%d", result);
        printf("%s\n", buffer);
    } else {
        printf("Empty AST\n");
    }
}