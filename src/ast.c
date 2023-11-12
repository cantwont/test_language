//
// Created by gabriel on 11/12/2023.
//

#include "../include/ast.h"
#include <stdlib.h>

ASTNode* create_number_node(int value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_NUMBER;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* create_addition_node(ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_ADDITION;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* create_subtraction_node(ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_SUBTRACTION;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* create_multiplication_node(ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_MULTIPLICATION;
    node->left = left;
    node->right = right;
    return node;
}

void destroy_ast(ASTNode* root) {
    if (root == NULL) {
        return;
    }

    destroy_ast(root->left);
    destroy_ast(root->right);
    free(root);
}
