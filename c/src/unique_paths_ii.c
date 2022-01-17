#include "unique_paths_ii.h"

#include <stdlib.h>

int uniquePathsWithObstacles_63_1(int **obstacleGrid, int obstacleGridSize,
                                  int *obstacleGridColSize) {
    const int m = obstacleGridSize, n = obstacleGridColSize[0];
    int *dp = (int *) calloc(n, sizeof(int));
    for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j)
        dp[j] = 1;
    for (int i = 1, j; i < m; ++i) {
        if (dp[0] != 0 && obstacleGrid[i][0] != 0)
            dp[0] = 0;
        for (j = 1; j < n; ++j)
            dp[j] = obstacleGrid[i][j] == 1 ? 0 : dp[j] + dp[j - 1];
    }
    int ret = dp[n - 1];
    free(dp);
    return ret;
}
