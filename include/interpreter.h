//
// Created by gabriel on 11/11/2023.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "../include/parser.h"

typedef enum {
    OPERATION_ADD,
    OPERATION_SUBTRACTION
} BinaryOperation;

typedef struct {
    int value;
    BinaryOperation operation;
} ExpressionNode;

int evaluate(ASTNode* node);
void interpret(ASTNode* node, char* buffer);

#endif //INTERPRETER_H
