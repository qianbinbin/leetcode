#include "distinct_subsequences.h"

#include <stdlib.h>
#include <string.h>

int numDistinct_115_1(char *s, char *t) {
    const size_t m = strlen(s), n = strlen(t);
    if (m < n) return 0;

    int **dp = (int **) malloc((m + 1) * sizeof(int *));
    for (size_t i = 0; i <= m; ++i)
        dp[i] = (int *) calloc(n + 1, sizeof(int));

    dp[0][0] = 1;
    for (size_t i = 1, j, e; i <= m; ++i) {
        dp[i][0] = 1;
        for (j = 1, e = i < n ? i : n; j <= e; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int ret = dp[m][n];
    for (size_t i = 0; i <= m; ++i) free(dp[i]);
    free(dp);
    return ret;
}
