#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"

typedef struct {
    Lexer* lexer;
} Parser;

// Function declarations
Parser* init_parser(Lexer* lexer);
ASTNode* parse_number(Parser* parser);
ASTNode* parse_term(Parser* parser);
ASTNode* parse_expression(Parser* parser);
void print_ast(ASTNode* node, int level);
ASTNode* parse_program(Parser* parser);
void destroy_parser(Parser* parser);

#endif // PARSER_H