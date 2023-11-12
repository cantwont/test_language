//
// Created by gabriel on 11/11/2023.
//

#include "../include/parser.h"
#include <stdio.h>
#include <stdlib.h>

#include "../include/lexer.h"

Parser* init_parser(Lexer* lexer) {
    Parser* parser = (Parser*)malloc(sizeof(Parser));
    parser->lexer = lexer;
    return parser;
}

ASTNode* create_ast_node(ASTNodeType type, int value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* parse_number(Parser* parser) {
    Token token = get_next_token(parser->lexer);

    if (token.type == TOKEN_NUMBER) {
        return create_ast_node(NODE_NUMBER, atoi(token.lexeme));
    } else {
        printf("ERR: Expected a number\n");
        return NULL;
    }
}

ASTNode* parse_term(Parser* parser) {
    return parse_number(parser);
}

ASTNode* parse_expression(Parser* parser) {
    ASTNode* left = parse_term(parser);

    Token token = get_next_token(parser->lexer);

    while (token.type == TOKEN_PLUS || token.type == TOKEN_MINUS) {
        ASTNode* right = parse_term(parser);

        if (token.type == TOKEN_PLUS) {
            left = create_ast_node(NODE_ADDITION, 0);
        } else {
            left = create_ast_node(NODE_SUBTRACTION, 0);
        }

        left->left = left;
        left->right = right;

        unget_token(parser->lexer, token);
        token = get_next_token(parser->lexer);
    }
    unget_token(parser->lexer, token);
    return left;
}

ASTNode* parse_program(Parser* parser) {
    return parse_expression(parser);
}

void destroy_parser(Parser* parser) {
    free(parser);
}