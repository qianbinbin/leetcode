#include "longest_valid_parentheses.h"

#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses_32_1(char *s) {
    if (s == NULL) return 0;

    int longest = 0;
    int top = -1;
    int start = -1;
    const int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            ++top;
        } else {
            if (top == -1) {
                start = i;
            } else {
                --top;
                if (top == -1)
                    longest = MAX(longest, i - start);
            }
        }
    }
    top = -1;
    start = len;
    for (int i = len - 1; i >= 0; --i) {
        if (s[i] == ')') {
            ++top;
        } else {
            if (top == -1) {
                start = i;
            } else {
                --top;
                if (top == -1)
                    longest = MAX(longest, start - i);
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
        } else {
            --top;
            if (top == -1)
                stack[++top] = i;
            else
                longest = MAX(longest, i - stack[top]);
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
                if (j >= 0 && s[j] == '(')
                    dp[i] = dp[i - 1] + 2 + (j > 0 ? dp[j - 1] : 0);
                else
                    dp[i] = 0;
            }
            longest = MAX(longest, dp[i]);
        } else
            dp[i] = 0;
    }
    free(dp);
    return longest;
}
