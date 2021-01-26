#include "regular_expression_matching.h"

#include <stdlib.h>
#include <string.h>

#define MATCH(s, p) ((p) == '.' || (s) == (p))

bool isMatch_10_1(char *s, char *p) {
    if (*p == '\0')
        return *s == '\0';
    if (*s == '\0')
        return *(p + 1) == '*' && isMatch_10_1(s, p + 2);

    if (*(p + 1) == '*') {
        if (MATCH(*s, *p))
            return isMatch_10_1(s, p + 2) || isMatch_10_1(s + 1, p);
        return isMatch_10_1(s, p + 2);
    }
    return MATCH(*s, *p) && isMatch_10_1(s + 1, p + 1);
}

bool isMatch_10_2(char *s, char *p) {
    const size_t row = strlen(s) + 1, col = strlen(p) + 1;
    if (col == 1)
        return row == 1;

    bool **dp = (bool **) malloc(row * sizeof(bool *));
    for (size_t i = 0; i < row; ++i)
        dp[i] = (bool *) calloc(col, sizeof(bool));

    dp[0][0] = true;
    for (size_t j = 2; j < col && p[j - 1] == '*'; j += 2)
        dp[0][j] = true;
    if (row > 1) dp[1][1] = MATCH(s[0], p[0]);

    for (size_t i = 1; i < row; ++i) {
        for (size_t j = 2; j < col; ++j) {
            if (p[j - 1] != '*')
                dp[i][j] = dp[i - 1][j - 1] && MATCH(s[i - 1], p[j - 1]);
            else
                dp[i][j] = dp[i][j - 2] ||
                           (MATCH(s[i - 1], p[j - 2]) && dp[i - 1][j]);
        }
    }

    bool ret = dp[row - 1][col - 1];
    for (size_t i = 0; i < row; ++i) free(dp[i]);
    free(dp);
    return ret;
}
