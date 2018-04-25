#include <unique-paths-ii.h>
#include <stdlib.h>

int uniquePathsWithObstacles_63_1(int **obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if (obstacleGrid == NULL || obstacleGridRowSize < 1 || obstacleGridColSize < 1) return -1;
    if (obstacleGrid[obstacleGridRowSize - 1][obstacleGridColSize - 1] == 1) return 0;
    if (obstacleGridRowSize == 1 && obstacleGridColSize == 1) return 1;
    if (obstacleGridRowSize == 1)
        return uniquePathsWithObstacles_63_1(obstacleGrid, obstacleGridRowSize, obstacleGridColSize - 1);
    if (obstacleGridColSize == 1)
        return uniquePathsWithObstacles_63_1(obstacleGrid, obstacleGridRowSize - 1, obstacleGridColSize);
    return uniquePathsWithObstacles_63_1(obstacleGrid, obstacleGridRowSize - 1, obstacleGridColSize) +
           uniquePathsWithObstacles_63_1(obstacleGrid, obstacleGridRowSize, obstacleGridColSize - 1);
}

int uniquePathsWithObstacles_63_2(int **obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if (obstacleGrid == NULL || obstacleGridRowSize < 1 || obstacleGridColSize < 1) return -1;

    int *dp = (int *) calloc(obstacleGridColSize, sizeof(int));
    dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int i = 0; i < obstacleGridRowSize; ++i) {
        if (dp[0] == 1 && obstacleGrid[i][0] == 0) {
            dp[0] = 1;
        } else {
            dp[0] = 0;
        }
        for (int j = 1; j < obstacleGridColSize; ++j) {
            dp[j] = obstacleGrid[i][j] == 1 ? 0 : dp[j - 1] + dp[j];
        }
    }
    int ret = dp[obstacleGridColSize - 1];
    free(dp);
    return ret;
}
