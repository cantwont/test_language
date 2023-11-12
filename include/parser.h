//
// Created by gabriel on 11/11/2023.
//

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum {
    NODE_NUMBER,
    NODE_ADDITION,
    NODE_SUBTRACTION,
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    int value;  // Only used for NODE_NUMBER
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

typedef struct {
    Lexer* lexer;
} Parser;

Parser* init_parser(Lexer* lexer);
ASTNode* parse(Parser* parser);
void destroy_parser(Parser* parser);
void unget_token(Lexer* lexer, Token token);

#endif //PARSER_H
