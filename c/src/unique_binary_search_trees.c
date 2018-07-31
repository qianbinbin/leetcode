#include "unique_binary_search_trees.h"

#include <stdlib.h>

int numTrees_96_1(int n) {
    if (n < 2) return 1;

    int *dp = (int *) calloc(n + 1, sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    for (int count = 2; count <= n; ++count) {
        for (int left = 0; left < count; ++left)
            dp[count] += dp[left] * dp[count - left - 1];
    }
    int ret = dp[n];
    free(dp);
    return ret;
}

int numTrees_96_2(int n) {
    if (n < 2) return 1;
    int64_t ret = 1;
    for (int i = 1; i <= n; ++i)
        ret = ret * (n + i) / i;
    return (int) (ret / (n + 1));
}
