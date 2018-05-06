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

static void num_distinct_dfs(char *s, const size_t len1, size_t i1,
                             char *t, const size_t len2, size_t i2, int *count) {
    if (i2 == len2) {
        ++(*count);
        return;
    }
    if (i1 == len1) return;
    for (size_t i = i1; i < len1; ++i) {
        if (s[i] == t[i2]) {
            num_distinct_dfs(s, len1, i + 1, t, len2, i2 + 1, count);
        }
    }
}

int numDistinct_115_2(char *s, char *t) {
    if (s == NULL || t == NULL) return -1;
    const size_t len1 = strlen(s), len2 = strlen(t);
    if (len1 < 1 || len2 < 1 || len1 < len2) return 0;

    int count = 0;
    num_distinct_dfs(s, len1, 0, t, len2, 0, &count);
    return count;
}
