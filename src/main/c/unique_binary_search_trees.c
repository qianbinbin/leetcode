#include <unique_binary_search_trees.h>
#include <stdlib.h>
#include <string.h>

int numTrees_96(int n) {
    if (n < 0) return 0;

    int *dp = (int *) malloc((n + 1) * sizeof(int));
    memset(dp, 0, (n + 1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
