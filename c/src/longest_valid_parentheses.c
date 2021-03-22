#include "longest_valid_parentheses.h"

#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses_32_1(char *s) {
    int longest = 0;
    int top = -1;
    char *p, *pre;
    for (p = s, pre = p - 1; *p; ++p) {
        if (*p == '(') {
            ++top;
        } else if (*p == ')') {
            if (top >= 0) {
                if (--top == -1)
                    longest = MAX(longest, p - pre);
            } else {
                pre = p;
            }
        }
    }
    top = -1;
    for (pre = p--; p >= s; --p) {
        if (*p == ')') {
            ++top;
        } else if (*p == '(') {
            if (top >= 0) {
                if (--top == -1)
                    longest = MAX(longest, pre - p);
            } else {
                pre = p;
            }
        }
    }
    return longest;
}

int longestValidParentheses_32_2(char *s) {
    int capacity = 16;
    char **stack = (char **) malloc(capacity * sizeof(char *));
    stack[0] = s - 1;
    int size = 1;
    int longest = 0;
    for (; *s; ++s) {
        if (*s == '(') {
            if (size >= capacity)
                stack = (char **) realloc(stack,
                                          (capacity *= 2) * sizeof(char *));
            stack[size++] = s;
        } else if (*s == ')') {
            if (--size > 0) {
                longest = MAX(longest, s - stack[size - 1]);
            } else {
                stack[size++] = s;
            }
        }
    }
    free(stack);
    return longest;
}

int longestValidParentheses_32_3(char *s) {
    int const len = (int) strlen(s);
    if (len < 2) return 0;

    int *dp = (int *) malloc(len * sizeof(int));
    dp[0] = 0;
    dp[1] = (s[0] == '(' && s[1] == ')') ? 2 : 0;
    int longest = dp[1];
    for (int i = 2, j; i < len; ++i) {
        if (s[i] == '(') {
            dp[i] = 0;
        } else if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = dp[i - 2] + 2;
            } else if (s[i - 1] == ')') {
                j = i - dp[i - 1] - 1;
                if (j >= 0 && s[j] == '(')
                    dp[i] = dp[i - 1] + 2 + (j > 0 ? dp[j - 1] : 0);
                else
                    dp[i] = 0;
            }
            longest = MAX(longest, dp[i]);
        }
    }
    free(dp);
    return longest;
}
