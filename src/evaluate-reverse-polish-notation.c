#include <evaluate-reverse-polish-notation.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define IS_OPERATOR(s) ((s) == '+' || (s) == '-' || (s) == '*' || (s) == '/')

int evalRPN_150(char **tokens, int tokensSize) {
    if (tokens == NULL || tokensSize < 0) return INT_MIN;

    int *stack = (int *) malloc(tokensSize * sizeof(int));
    int top = -1;
    int x, y;
    bool valid = true;
    for (int i = 0; i < tokensSize; ++i) {
        if (strlen(tokens[i]) == 1 && IS_OPERATOR(tokens[i][0])) {
            if (top < 1) {
                valid = false;
                break;
            } else {
                y = stack[top--];
                x = stack[top--];
                switch (tokens[i][0]) {
                    case '+':
                        x += y;
                        break;
                    case '-':
                        x -= y;
                        break;
                    case '*':
                        x *= y;
                        break;
                    case '/':
                        x /= y;
                        break;
                }
                stack[++top] = x;
            }
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    int ret;
    if (top == 0 && valid) {
        ret = stack[0];
    } else {
        ret = INT_MIN;
    }
    free(stack);
    return ret;
}
