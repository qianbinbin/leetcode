#include <unique-paths.h>
#include <stdlib.h>

int uniquePaths_62_1(int m, int n) {
    if (m < 1 || n < 1) return 0;
    if (m == 1 || n == 1) return 1;
    return uniquePaths_62_1(m - 1, n) + uniquePaths_62_1(m, n - 1);
}

int uniquePaths_62_2(int m, int n) {
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

static int64_t factorial(int n, int start) {
    int64_t ret = 1;
    for (int i = start; i <= n; ++i)
        ret *= i;
    return ret;
}

static int64_t combination(int m, int n) {
    if (m == 0) return 1;
    if (m < 0 || n < 0 || m < n) return 0;
    if (m - n < n)
        n = m - n;
    int64_t ret = factorial(m, m - n + 1);
    ret /= factorial(n, 1);
    return ret;
}

int uniquePaths_62_3(int m, int n) {
    if (m < 1 || n < 1) return 0;
    return combination(m + n - 2, m - 1);
}
