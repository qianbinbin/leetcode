#include <triangle.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal_120(int **triangle, int triangleRowSize, int *triangleColSizes) {
    if (triangle == NULL || triangleRowSize < 1 || triangleColSizes == NULL) return -1;

    int *dp = (int *) malloc(triangleColSizes[triangleRowSize - 1] * sizeof(int));
    memcpy(dp, triangle[triangleRowSize - 1], triangleColSizes[triangleRowSize - 1] * sizeof(int));

    for (int row = triangleRowSize - 2; row >= 0; --row) {
        for (int col = 0; col < triangleColSizes[row]; ++col) {
            dp[col] = MIN(dp[col], dp[col + 1]) + triangle[row][col];
        }
    }
    int ret = dp[0];
    free(dp);
    return ret;
}