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

int longestValidParentheses_32_3(char *s) {
    if (s == NULL) return 0;

    const int len = strlen(s);
    if (len < 2) return 0;
    int *dp = (int *) malloc(len * sizeof(int));
    dp[0] = 0;
    dp[1] = (s[1] == ')' && s[0] == '(') ? 2 : 0;
    int longest = dp[1];
    int i, j;
    for (i = 2; i < len; ++i) {
        if (s[i] == ')') {
            if (s[i - 1] == '(')
                dp[i] = dp[i - 2] + 2;
            else if (s[i - 1] == ')') {
                j = i - dp[i - 1] - 1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] = dp[i - 1] + 2 + (j > 0 ? dp[j - 1] : 0);
                } else dp[i] = 0;
            }
        } else dp[i] = 0;
        longest = dp[i] > longest ? dp[i] : longest;
    }
    return longest;
}

int longestValidParentheses_32_4(char *s) {
    if (s == NULL) return 0;

    int longest = 0;
    int top = -1;
    int start = -1;
    const int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            ++top;
        } else if (s[i] == ')') {
            if (top == -1) {
                start = i;
            } else {
                --top;
                if (top == -1) {
                    longest = (i - start) > longest ? (i - start) : longest;
                }
            }
        }
    }
    top = -1;
    start = len;
    for (int i = len - 1; i >= 0; --i) {
        if (s[i] == ')') {
            ++top;
        } else if (s[i] == '(') {
            if (top == -1) {
                start = i;
            } else {
                --top;
                if (top == -1) {
                    longest = (start - i) > longest ? (start - i) : longest;
                }
            }
        }
    }
    return longest;
}
