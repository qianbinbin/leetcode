#include "valid_parentheses.h"

#include <stdlib.h>
#include <string.h>

bool isValid_20_1(char *s) {
    if (s == NULL) return false;

    char *stack = (char *) malloc(strlen(s));
    int top = -1;
    while (*s != '\0') {
        switch (*s) {
            case '(':
                stack[++top] = *s;
                break;
            case ')':
                if (top == -1 || stack[top--] != '(') {
                    free(stack);
                    return false;
                }
                break;
            case '{':
                stack[++top] = *s;
                break;
            case '}':
                if (top == -1 || stack[top--] != '{') {
                    free(stack);
                    return false;
                }
                break;
            case '[':
                stack[++top] = *s;
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
        ++s;
    }
    free(stack);
    return top == -1;
}
