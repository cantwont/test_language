#include "../include/lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* token_type_to_string(TokenType type) {
    switch (type) {
        case TOKEN_VAR:
            return "VAR";
        case TOKEN_PRINT:
            return "PRINT";
        case TOKEN_IF:
            return "IF";
        case TOKEN_ELSE:
            return "ELSE";
        case TOKEN_WHILE:
            return "WHILE";
        case TOKEN_FUNC:
            return "FUNC";
        case TOKEN_RETURN:
            return "RETURN";
        case TOKEN_EQUAL:
            return "EQUAL";
        case TOKEN_SEMICOLON:
            return "SEMICOLON";
        default:
            return "UNKNOWN";
    }
}

const char* token_to_type_string(TokenType token_type) {
    switch (token_type) {
        case TOKEN_IDENTIFIER:
            return "IDENTIFIER";
        case TOKEN_NUMBER:
            return "NUMBER";
        case TOKEN_PLUS:
            return "PLUS";
        case TOKEN_MINUS:
            return "MINUS";
        case TOKEN_MULTIPLY:
            return "MULTIPLY";
        case TOKEN_DIVIDE:
            return "DIVIDE";
        case TOKEN_EOF:
            return "EOF";
        case TOKEN_IF:
            return "IF";
        case TOKEN_ELSE:
            return "ELSE";
        case TOKEN_WHILE:
            return "WHILE";
        case TOKEN_FUNC:
            return "FUNC";
        case TOKEN_RETURN:
            return "RETURN";
        case TOKEN_EQUAL:
            return "EQUAL";
        case TOKEN_SEMICOLON:
            return "SEMICOLON";
        default:
            return "UNKNOWN";
    }
}

Lexer* init_lexer(const char* source_code) {
    Lexer* lexer = (Lexer*)malloc(sizeof(Lexer));
    lexer->source_code = source_code;
    lexer->current_position = 0;
    return lexer;
}

Token get_next_token(Lexer* lexer) {
    while (isspace(lexer->source_code[lexer->current_position])) {
        lexer->current_position++;
    }

    if (lexer->source_code[lexer->current_position] == '\0') {
        Token token;
        token.type = TOKEN_EOF;
        token.lexeme = NULL;
        return token;
    }

    if (isalpha(lexer->source_code[lexer->current_position]) || lexer->source_code[lexer->current_position] == '_') {
        int length = 0;
        while (isalnum(lexer->source_code[lexer->current_position + length]) || lexer->source_code[lexer->current_position + length] == '_') {
            length++;
        }

        char* identifier = (char*)malloc(length + 1);
        strncpy(identifier, lexer->source_code + lexer->current_position, length);
        identifier[length] = '\0';

        lexer->current_position += length;

        Token token;
        token.lexeme = identifier;

        if (strcmp(identifier, "var") == 0) {
            token.type = TOKEN_VAR;
        } else if (strcmp(identifier, "print") == 0) {
            token.type = TOKEN_PRINT;
        } else if (strcmp(identifier, "if") == 0) {
            token.type = TOKEN_IF;
        } else if (strcmp(identifier, "else") == 0) {
            token.type = TOKEN_ELSE;
        } else if (strcmp(identifier, "while") == 0) {
            token.type = TOKEN_WHILE;
        } else if (strcmp(identifier, "func") == 0) {
            token.type = TOKEN_FUNC;
        } else if (strcmp(identifier, "return") == 0) {
            token.type = TOKEN_RETURN;
        } else {
            token.type = TOKEN_IDENTIFIER;
        }

        return token;
    }

    if (isdigit(lexer->source_code[lexer->current_position])) {
        int length = 0;
        while (isdigit(lexer->source_code[lexer->current_position + length])) {
            length++;
        }

        char* number = (char*)malloc(length + 1);
        strncpy(number, lexer->source_code + lexer->current_position, length);
        number[length] = '\0';

        lexer->current_position += length;

        Token token;
        token.type = TOKEN_NUMBER;
        token.lexeme = number;
        token.value = atoi(number);

        return token;
    }

    switch (lexer->source_code[lexer->current_position]) {
        case '+':
            lexer->current_position++;
            Token token_plus;
            token_plus.type = TOKEN_PLUS;
            token_plus.lexeme = "+";
            return token_plus;
        case '-':
            lexer->current_position++;
            Token token_minus;
            token_minus.type = TOKEN_MINUS;
            token_minus.lexeme = "-";
            return token_minus;
        case '*':
            lexer->current_position++;
            Token token_multiply;
            token_multiply.type = TOKEN_MULTIPLY;
            token_multiply.lexeme = "*";
            return token_multiply;
        case '/':
            lexer->current_position++;
            Token token_divide;
            token_divide.type = TOKEN_DIVIDE;
            token_divide.lexeme = "/";
            return token_divide;
        case '=':
            lexer->current_position++;
            Token token_equal;
            token_equal.type = TOKEN_EQUAL;
            token_equal.lexeme = "=";
            return token_equal;
        case ';':
            lexer->current_position++;
            Token token_semicolon;
            token_semicolon.type = TOKEN_SEMICOLON;
            token_semicolon.lexeme = ";";
            return token_semicolon;
        default:
            fprintf(stderr, "Error: Unknown token: %c\n", lexer->source_code[lexer->current_position]);
            Token token_error;
            token_error.type = TOKEN_EOF;
            token_error.lexeme = NULL;
            return token_error;
    }
}


void unget_token(Lexer* lexer, Token token) {
    if (token.lexeme != NULL) {
        lexer->current_position -= strlen(token.lexeme);
        free(token.lexeme);
    }
}

void destroy_lexer(Lexer* lexer) {
    free(lexer);
}