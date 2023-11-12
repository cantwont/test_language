//
// Created by gabriel on 11/11/2023.
//

#ifndef LEXER_H
#define LEXER_H
#include <stddef.h>

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_EOF,
} TokenType;

typedef struct {
    TokenType type;
    char* lexeme;
} Token;

typedef struct {
    const char* source_code;
    size_t current_position;
} Lexer;

Lexer* init_lexer(const char* source_code);
Token get_next_token(Lexer* lexer);
void destroy_lexer(Lexer* lexer);

#endif //LEXER_H
