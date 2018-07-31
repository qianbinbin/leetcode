#include "unique_paths_ii.h"

#include <stdlib.h>

int uniquePathsWithObstacles_63_1(int **obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if (obstacleGrid == NULL || obstacleGridRowSize < 1 || obstacleGridColSize < 1) return -1;

    const int row = obstacleGridRowSize, col = obstacleGridColSize;
    int **dp = (int **) malloc(row * sizeof(int *));
    for (int i = 0; i < row; ++i) dp[i] = (int *) calloc(col, sizeof(int));
    for (int j = 0; j < col && obstacleGrid[0][j] == 0; ++j) dp[0][j] = 1;
    for (int i = 0; i < row && obstacleGrid[i][0] == 0; ++i) dp[i][0] = 1;
    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    int ret = dp[row - 1][col - 1];
    for (int i = 0; i < row; ++i) free(dp[i]);
    free(dp);
    return ret;
}
