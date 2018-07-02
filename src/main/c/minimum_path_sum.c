#include "minimum_path_sum.h"

#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minPathSum_64_1(int **grid, int gridRowSize, int gridColSize) {
    if (grid == NULL || gridRowSize < 0 || gridColSize < 0) return -1;
    if (gridRowSize == 0 || gridColSize == 0) return 0;

    int *dp = (int *) malloc(gridColSize * sizeof(int));
    dp[0] = grid[0][0];
    for (int i = 1; i < gridColSize; ++i)
        dp[i] = dp[i - 1] + grid[0][i];

    for (int i = 1; i < gridRowSize; ++i) {
        dp[0] += grid[i][0];
        for (int j = 1; j < gridColSize; ++j) {
            dp[j] = MIN(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    int ret = dp[gridColSize - 1];
    free(dp);
    return ret;
}
