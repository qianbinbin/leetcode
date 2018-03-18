#include <longest-valid-parentheses.h>
#include <stdbool.h>
#include <string.h>

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
