#include "longest_palindromic_substring.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *longestPalindrome_5_1(char *s) {
    if (s == NULL) return NULL;

    const int len = (const int) strlen(s);
    bool **dp = (bool **) malloc(len * sizeof(bool *));
    for (int i = 0; i < len; ++i) dp[i] = (bool *) calloc(len, sizeof(bool));

    int longest = 0, start = 0;
    for (int i = len - 1; i >= 0; --i) {
        for (int j = i; j < len; ++j) {
            if (i == j || (s[i] == s[j] && (i + 1 == j || dp[i + 1][j - 1]))) {
                dp[i][j] = true;
                if (j - i + 1 > longest) {
                    longest = j - i + 1;
                    start = i;
                }
            }
        }
    }
    for (int i = 0; i < len; ++i) free(dp[i]);
    free(dp);

    char *ret = (char *) malloc(longest + 1);
    ret[longest] = '\0';
    memcpy(ret, s + start, longest);
    return ret;
}
