#include <stdio.h>
#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/interpreter.h"
#include <stdlib.h>
#include <string.h>

char buffer[BUFSIZ];

void test_lexer(const char* input, const TokenType expected_tokens[], size_t expected_tokens_count) {
    Lexer* lexer = init_lexer(input);

    for (size_t i = 0; i < expected_tokens_count; ++i) {
        Token token = get_next_token(lexer);

        printf("Token Type: %s, Expected Type: %s\n",
               token_type_to_string(token.type), token_type_to_string(expected_tokens[i]));

        if (token.type != expected_tokens[i]) {
            printf("Assertion failed: Token type does not match expected type!\n");
            printf("Exiting...\n");
            return;
        }
    }

    printf("Lexer test successful!\n");

    destroy_lexer(lexer);
}

void test_parser(const char* input) {
    Lexer* lexer = init_lexer(input);
    Parser* parser = init_parser(lexer);
    destroy_parser(parser);
    destroy_lexer(lexer);
}

void test_interpreter(const char* input, int expected_output) {
    char buffer[BUFSIZ];
    Lexer* lexer = init_lexer(input);
    Parser* parser = init_parser(lexer);
    ASTNode* ast = parse_expression(parser);

    memset(buffer, 0, sizeof(buffer));

    interpret(ast, buffer);
    printf("Interpreting: %s\n", buffer);

    int actual_output = atoi(buffer);

    if (actual_output == expected_output) {
        printf("Interpreter test succeeded!\n");
    } else {
        printf("Interpreter test failed! Expected: %d, Actual: %d\n", expected_output, actual_output);
    }

    destroy_parser(parser);
    destroy_lexer(lexer);
}


int main() {
    //test_lexer("19 + 2", (TokenType[]){TOKEN_NUMBER, TOKEN_PLUS, TOKEN_NUMBER, TOKEN_EOF}, 4);
    //test_parser("19 + 2");
    //test_interpreter("19 + 2", 21);

    //test_lexer("19", (TokenType[]){TOKEN_NUMBER, TOKEN_EOF}, 2);
    //test_parser("19");
    test_interpreter("4+4", 8);
    test_interpreter("0+4", 4);
    test_interpreter("9-3", 6);

    return 0;
}