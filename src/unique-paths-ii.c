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
