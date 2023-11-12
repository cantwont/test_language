//
// Created by gabriel on 11/11/2023.
//

#include "../include/lexer.h"
#include <stdlib.h>

Lexer* init_lexer(const char* source_code) {
    Lexer* lexer = (Lexer*)malloc(sizeof(Lexer));
    lexer->source_code = source_code;
    lexer->current_position = 0;
    return lexer;
}

Token get_next_token(Lexer* lexer) {
    Token token;
    token.type = TOKEN_EOF;
    token.lexeme = NULL;

    return token;
}

void destroy_lexer(Lexer* lexer) {
    free(lexer);
}