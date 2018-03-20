#include <longest-valid-parentheses.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses_32_1(char *s) {
    if (s == NULL) return 0;

    int top = -1;
    int longest = 0, length = 0;
    char *start = s;
    while (true) {
        if (top == -1) {
            longest = length > longest ? length : longest;
        }
        if (*s == '(') {
            ++top;
            ++length;
            ++s;
        } else if (*s == ')') {
            if (top == -1) {
                length = 0;
                start = s + 1;
            } else {
                --top;
                ++length;
            }
            ++s;
        } else if (*s == '\0') {
            if (top == -1) {
                break;
            } else {
                length = 0;
                top = -1;
                ++start;
                s = start;
            }
        }
    }
    return longest;
}

int longestValidParentheses_32_2(char *s) {
    if (s == NULL) return 0;

    int *stack = (int *) malloc((strlen(s) + 1) * sizeof(int));
    stack[0] = -1;
    int top = 0;
    int longest = 0;
    const int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else if (s[i] == ')') {
            --top;
            if (top == -1) stack[++top] = i;
            else {
                longest = (i - stack[top]) > longest ? (i - stack[top]) : longest;
            }
        }
    }
    free(stack);
    return longest;
}
