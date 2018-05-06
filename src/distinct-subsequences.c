#include <distinct-subsequences.h>
#include <stdlib.h>
#include <string.h>

int numDistinct_115_1(char *s, char *t) {
    if (s == NULL || t == NULL) return -1;
    const size_t len1 = strlen(s), len2 = strlen(t);
    if (len1 < 1 || len2 < 1 || len1 < len2) return 0;

    int **dp = (int **) malloc(len1 * sizeof(int *));
    int count = 0;
    for (int i = 0; i < len1; ++i) {
        dp[i] = (int *) malloc(len2 * sizeof(int));
        if (s[i] == t[0]) ++count;
        dp[i][0] = count;
    }
    for (int j = 1; j < len2; ++j) dp[0][j] = 0;

    for (int i = 1; i < len1; ++i) {
        for (int j = 1; j < len2; ++j) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ret = dp[len1 - 1][len2 - 1];
    for (int i = 0; i < len1; ++i) free(dp[i]);
    free(dp);
    return ret;
}
