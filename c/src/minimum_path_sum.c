#include "minimum_path_sum.h"

#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minPathSum_64_1(int **grid, int gridSize, int *gridColSize) {
    int const m = gridSize, n = gridColSize[0];
    int *dp = (int *) malloc(n * sizeof(int));
    dp[0] = grid[0][0];
    for (int i = 1; i < n; ++i)
        dp[i] = dp[i - 1] + grid[0][i];
    for (int i = 1; i < m; ++i) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; ++j) {
            dp[j] = MIN(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    int ret = dp[n - 1];
    free(dp);
    return ret;
}
