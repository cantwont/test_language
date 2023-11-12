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

void test_interpreter(const char* input, double expected_output) {
    char buffer[BUFSIZ];
    Lexer* lexer = init_lexer(input);
    Parser* parser = init_parser(lexer);
    ASTNode* ast = parse_expression(parser);

    memset(buffer, 0, sizeof(buffer));

    interpret(ast, buffer);
    printf("Interpreting: %s\n", buffer);

    double actual_output = atof(buffer);

    if (actual_output == expected_output) {
        printf("Interpreter test succeeded!\n");
    } else {
        printf("Interpreter test failed! Expected: %f, Actual: %f\n", expected_output, actual_output);
    }

    destroy_parser(parser);
    destroy_lexer(lexer);
}


int main() {
    test_interpreter("5*2", 10);
    test_interpreter("14/8", 1.74); // WILL FAIL, TESTING ACCURACY FOR THIS ONE
    test_interpreter("14/8", 1.75);
    return 0;
}