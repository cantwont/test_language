#include "../include/interpreter.h"
#include <stdio.h>
#include <stdlib.h>

int evaluate(ASTNode* node) {
    if (node == NULL) {
        return 0;
    }

    switch (node->type) {
        case NODE_NUMBER:
            return node->value;
        case NODE_ADDITION:
            return evaluate(node->left) + evaluate(node->right);
        case NODE_SUBTRACTION:
            return evaluate(node->left) - evaluate(node->right);
        case NODE_MULTIPLICATION:
            return evaluate(node->left) * evaluate(node->right);
        case NODE_DIVISION:
            return evaluate(node->left) / evaluate(node->right);
        default:
            return 0;
    }
}

void interpret(ASTNode* node, char* buffer) {
    if (node == NULL) {
        snprintf(buffer, BUFSIZ, "Error: Null node");
        return;
    }

    int result;

    switch (node->type) {
        case NODE_NUMBER:
            snprintf(buffer, BUFSIZ, "%d", node->value);
            break;
        case NODE_ADDITION: {
            char leftBuffer[BUFSIZ];
            char rightBuffer[BUFSIZ];

            interpret(node->left, leftBuffer);
            interpret(node->right, rightBuffer);

            printf("Debug NODE_ADDITION: left=%s right=%s\n", leftBuffer, rightBuffer);

            int leftValueAddition = atoi(leftBuffer);
            int rightValueAddition = atoi(rightBuffer);

            printf("Debug NODE_ADDITION: leftValue=%d rightValue=%d\n", leftValueAddition, rightValueAddition);

            result = leftValueAddition + rightValueAddition;
            snprintf(buffer, BUFSIZ, "%d", result);
            break;
        }
        case NODE_SUBTRACTION: {
            char leftBuffer[BUFSIZ];
            char rightBuffer[BUFSIZ];

            interpret(node->left, leftBuffer);
            interpret(node->right, rightBuffer);

            printf("Debug NODE_SUBTRACTION: left=%s right=%s\n", leftBuffer, rightBuffer);

            int leftValueSubtraction = atoi(leftBuffer);
            int rightValueSubtraction = atoi(rightBuffer);

            printf("Debug NODE_SUBTRACTION: leftValue=%d rightValue=%d\n", leftValueSubtraction, rightValueSubtraction);

            result = leftValueSubtraction - rightValueSubtraction;
            snprintf(buffer, BUFSIZ, "%d", result);
            break;
        }
        case NODE_MULTIPLICATION: {
            char leftBuffer[BUFSIZ];
            char rightBuffer[BUFSIZ];

            interpret(node->left, leftBuffer);
            interpret(node->right, rightBuffer);

            printf("Debug NODE_MULTIPLICATION: left=%s right=%s\n", leftBuffer, rightBuffer);

            int leftValueMultiplication = atoi(leftBuffer);
            int rightValueMultiplication = atoi(rightBuffer);

            printf("Debug NODE_MULTIPLICATION: leftValue=%d rightValue=%d\n", leftValueMultiplication, rightValueMultiplication);

            result = leftValueMultiplication * rightValueMultiplication;
            snprintf(buffer, BUFSIZ, "%d", result);
            break;
        }
        case NODE_DIVISION: {
            char leftBuffer[BUFSIZ];
            char rightBuffer[BUFSIZ];

            interpret(node->left, leftBuffer);
            interpret(node->right, rightBuffer);

            printf("Debug NODE_DIVISION: left=%s right=%s\n", leftBuffer, rightBuffer);

            int leftValueDivision = atoi(leftBuffer);
            int rightValueDivision = atoi(rightBuffer);

            printf("Debug NODE_DIVISION: leftValue=%d rightValue=%d\n", leftValueDivision, rightValueDivision);

            result = leftValueDivision / rightValueDivision;
            snprintf(buffer, BUFSIZ, "%d", result);
            break;
        }
        default:
            snprintf(buffer, BUFSIZ, "Error: Unknown node type");
            break;
    }
}