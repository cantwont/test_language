//
// Created by gabriel on 11/11/2023.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../include/parser.h"

int evaluate(ASTNode* node);
void interpret(ASTNode* ast, char buffer[]);

#endif //INTERPRETER_H
