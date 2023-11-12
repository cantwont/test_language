#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

struct ASTNode;

typedef enum {
    NODE_NUMBER,
    NODE_ADDITION,
    NODE_SUBTRACTION,
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    int value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

typedef struct {
    Lexer* lexer;
} Parser;

Parser* init_parser(Lexer* lexer);
ASTNode* parse_number(Parser* parser);
ASTNode* parse_term(Parser* parser);
ASTNode* parse_expression(Parser* parser);
ASTNode* parse_program(Parser* parser);
void destroy_parser(Parser* parser);
void unget_token(Lexer* lexer, Token token);

#endif // PARSER_H