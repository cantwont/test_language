#include <stdio.h>
#include "../include/lexer.h"
#include "../include/parser.h"

const char* token_type_to_string(TokenType type) {
    switch (type) {
        case TOKEN_IDENTIFIER:
            return "IDENTIFIER";
        case TOKEN_NUMBER:
            return "NUMBER";
        case TOKEN_PLUS:
            return "PLUS";
        case TOKEN_MINUS:
            return "MINUS";
        case TOKEN_EOF:
            return "EOF";
        default:
            return "UNKNOWN";
    }
}

void test_lexer(const char* input, const TokenType expected_tokens[], size_t expected_tokens_count) {
    Lexer* lexer = init_lexer(input);

    for (size_t i = 0; i < expected_tokens_count; ++i) {
        Token token = get_next_token(lexer);

        // Print information about the token and expected type
        printf("Token Type: %s, Expected Type: %s\n",
               token_type_to_string(token.type), token_type_to_string(expected_tokens[i]));

        // Check if the token type matches the expected type
        if (token.type != expected_tokens[i]) {
            printf("Assertion failed: Token type does not match expected type!\n");
            printf("Exiting...\n");
            // Add a breakpoint here or set a trace signal to investigate further
            return;
        }
    }

    // Add a print statement to indicate the loop completed successfully
    printf("Lexer test successful!\n");

    destroy_lexer(lexer);
}

void test_parser(const char* input) {
    Lexer* lexer = init_lexer(input);
    Parser* parser = init_parser(lexer);
    destroy_parser(parser);
    destroy_lexer(lexer);
}

int main() {
    test_lexer("1 + 2", (TokenType[]){TOKEN_NUMBER, TOKEN_PLUS, TOKEN_NUMBER, TOKEN_EOF}, 4);
    test_parser("1 + 2");
    return 0;
}
