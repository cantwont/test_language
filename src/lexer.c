//
// Created by gabriel on 11/11/2023.
//

#include "../include/lexer.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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

    if (isdigit(lexer->source_code[lexer->current_position])) {
        Token token;
        token.type = TOKEN_NUMBER;
        int length = 0;

        while (isdigit(lexer->source_code[lexer->current_position + length])) {
            length++;
        }

        token.lexeme = (char*)malloc(length + 1);
        strncpy(token.lexeme, lexer->source_code + lexer->current_position, length);
        token.lexeme[length] = '\0';

        lexer->current_position += length;
        return token;
    }


    if (lexer->source_code[lexer->current_position] == '+') {
        Token token;
        token.type = TOKEN_PLUS;
        token.lexeme = NULL;
        lexer->current_position++;
        return token;
    }

    Token token;
    token.type = TOKEN_EOF;
    token.lexeme = NULL;
    return token;
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