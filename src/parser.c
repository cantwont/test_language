//
// Created by gabriel on 11/11/2023.
//

#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/interpreter.h"
#include "../include/ast.h"
#include <stdio.h>
#include <stdlib.h>

const char* token_type_to_string(TokenType type);

const char* ast_type_to_string(ASTNodeType type) {
    switch (type) {
        case NODE_NUMBER:
            return "NODE_NUMBER";
        case NODE_ADDITION:
            return "NODE_ADDITION";
        case NODE_SUBTRACTION:
            return "NODE_SUBTRACTION";
        case NODE_MULTIPLICATION:
            return "NODE_MULTIPLICATION";
        default:
            return "UNKNOWN_NODE_TYPE";
    }
}

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
        return create_ast_node(NODE_NUMBER, token.value);
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

    if (left == NULL) {
        return NULL;
    }

    Token token = get_next_token(parser->lexer);

    while (token.type == TOKEN_PLUS || token.type == TOKEN_MINUS || token.type == TOKEN_MULTIPLY || token.type == TOKEN_DIVIDE) {
        ASTNode* right = parse_term(parser);

        if (right == NULL) {
            return NULL;
        }

        ASTNodeType node_type;

        switch (token.type) {
            case TOKEN_PLUS:
                node_type = NODE_ADDITION;
                break;
            case TOKEN_MINUS:
                node_type = NODE_SUBTRACTION;
                break;
            case TOKEN_MULTIPLY:
                node_type = NODE_MULTIPLICATION;
                break;
            case TOKEN_DIVIDE:
                node_type = NODE_DIVISION;
                break;
            default:
                break;
        }

        ASTNode* new_node = create_ast_node(node_type, 0);
        new_node->left = left;
        new_node->right = right;

        left = new_node;

        printf("Token Type: %s\n", token_type_to_string(token.type));

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

        printf("Node: type=%s, value=%d\n", ast_type_to_string(node->type), node->value);

        print_ast(node->left, level + 1);
        print_ast(node->right, level + 1);
    }
}

ASTNode* parse_program(Parser* parser) {
    char buffer[BUFSIZ];
    ASTNode* ast = parse_expression(parser);

    if (ast != NULL) {
        printf("Interpreting:\n");
        print_ast(ast, 0);

        interpret(ast, buffer);

        printf("Result: %s\n", buffer);
    }

    return ast;
}

void destroy_parser(Parser* parser) {
    free(parser);
}