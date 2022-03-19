#include "evaluate_reverse_polish_notation.h"

#include <stdlib.h>

int evalRPN_150_1(char **tokens, int tokensSize) {
    int *stack = (int *) malloc(tokensSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < tokensSize; ++i) {
        if (tokens[i][0] == '+') {
            stack[top - 1] += stack[top];
            --top;
        } else if (tokens[i][0] == '-') {
            stack[top - 1] -= stack[top];
            --top;
        } else if (tokens[i][0] == '*') {
            stack[top - 1] *= stack[top];
            --top;
        } else if (tokens[i][0] == '/') {
            stack[top - 1] /= stack[top];
            --top;
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    int ret = stack[top];
    free(stack);
    return ret;
}
