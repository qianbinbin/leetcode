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
