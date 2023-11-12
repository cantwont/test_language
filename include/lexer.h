//
// Created by gabriel on 11/11/2023.
//

#ifndef LEXER_H
#define LEXER_H
#include <stddef.h>

typedef enum {
    TOKEN_EOF,
    TOKEN_VAR,
    TOKEN_IDENTIFIER,
    TOKEN_EQUAL,
    TOKEN_NUMBER,
    TOKEN_SEMICOLON,
    TOKEN_PRINT,
    TOKEN_IF,
    TOKEN_LEFT_BRACE,
    TOKEN_RIGHT_BRACE,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_FUNC,
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_COMMA,
    TOKEN_RETURN,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_STRING,
    TOKEN_STRING_LITERAL
} TokenType;

typedef struct {
    TokenType type;
    char* lexeme;
    int value;
    float float_value;
} Token;

typedef struct {
    const char* source_code;
    size_t current_position;
} Lexer;

Lexer* init_lexer(const char* source_code);
Token get_next_token(Lexer* lexer);
void unget_token(Lexer* lexer, Token token);
void destroy_lexer(Lexer* lexer);
const char* token_type_to_string(TokenType type);

#endif //LEXER_H
