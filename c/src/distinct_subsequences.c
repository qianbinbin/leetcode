#include "distinct_subsequences.h"

#include <stdlib.h>
#include <string.h>

int numDistinct_115_1(char *s, char *t) {
    if (s == NULL || t == NULL) return -1;

    const size_t len1 = strlen(s), len2 = strlen(t);
    if (len1 < 1 || len2 < 1 || len1 < len2) return 0;

    int **dp = (int **) malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; ++i) {
        dp[i] = (int *) calloc(len2 + 1, sizeof(int));
        dp[i][0] = 1;
    }

    for (size_t i = 1; i <= len1; ++i) {
        const size_t end = i < len2 ? i : len2;
        for (size_t j = 1; j <= end; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int ret = dp[len1][len2];
    for (size_t i = 0; i <= len1; ++i) free(dp[i]);
    free(dp);
    return ret;
}
