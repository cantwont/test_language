//
// Created by gabriel on 11/11/2023.
//

#include "../include/parser.h"
#include <stdio.h>
#include <stdlib.h>

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

        ASTNodeType node_type = (token.type == TOKEN_PLUS) ? NODE_ADDITION : NODE_SUBTRACTION;

        ASTNode* new_node = create_ast_node(node_type, 0);
        new_node->left = left;
        new_node->right = right;

        left = new_node;

        token = get_next_token(parser->lexer);
    }

    unget_token(parser->lexer, token);
    return left;
}

void print_ast(ASTNode* node, int level) {
    if (node != NULL) {
        for (int i = 0; i < level; i++) {
            printf("  ");
        }

        printf("Node: type=%d, value=%d\n", node->type, node->value);

        print_ast(node->left, level + 1);
        print_ast(node->right, level + 1);
    }
}


ASTNode* parse_program(Parser* parser) {
    ASTNode* ast = parse_expression(parser);
    print_ast(ast, 0);
    return ast;
}

void destroy_parser(Parser* parser) {
    free(parser);
}