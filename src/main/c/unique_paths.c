#include "unique_paths.h"

#include <stdlib.h>

int uniquePaths_62_1(int m, int n) {
    if (m < 1 || n < 1) return 0;
    if (m < n) {
        int tmp = m;
        m = n;
        n = tmp;
    }
    int *dp = (int *) calloc(n, sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    int ret = dp[n - 1];
    free(dp);
    return ret;
}

static int64_t factorial(int n, int k) {
    int64_t ret = 1;
    for (; k <= n; ++k)
        ret *= k;
    return ret;
}

static int64_t combination(int m, int n) {
    if (m - n < n)
        n = m - n;
    return factorial(m, m - n + 1) / factorial(n, 1);
}

int uniquePaths_62_2(int m, int n) {
    if (m < 1 || n < 1) return 0;
    return (int) combination(m + n - 2, m - 1);
}
