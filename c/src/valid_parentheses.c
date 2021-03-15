#include "valid_parentheses.h"

#include <stdlib.h>
#include <string.h>

bool isValid_20_1(char *s) {
    char *stack = (char *) malloc(strlen(s));
    int top = -1;
    for (; *s; ++s) {
        switch (*s) {
            case '(':
            case '{':
            case '[':
                stack[++top] = *s;
                break;
            case ')':
                if (top == -1 || stack[top--] != '(') {
                    free(stack);
                    return false;
                }
                break;
            case '}':
                if (top == -1 || stack[top--] != '{') {
                    free(stack);
                    return false;
                }
                break;
            case ']':
                if (top == -1 || stack[top--] != '[') {
                    free(stack);
                    return false;
                }
                break;
            default:
                break;
        }
    }
    free(stack);
    return top == -1;
}
