//
// Created by gabriel on 11/12/2023.
//

#ifndef AST_H
#define AST_H

typedef enum {
    NODE_NUMBER,
    NODE_ADDITION,
    NODE_SUBTRACTION,
    NODE_MULTIPLICATION,
    NODE_DIVISION,
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    int value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

const char* ast_type_to_string(ASTNodeType type);
ASTNode* create_number_node(int value);
ASTNode* create_addition_node(ASTNode* left, ASTNode* right);
ASTNode* create_subtraction_node(ASTNode* left, ASTNode* right);
ASTNode* create_multiplication_node(ASTNode* left, ASTNode* right);
ASTNode* create_division_node(ASTNode* left, ASTNode* right);
void destroy_ast(ASTNode* root);

#endif // AST_H