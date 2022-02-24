#include "triangle.h"

#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal_120_1(int **triangle, int triangleSize, int *triangleColSize) {
    int *dp = (int *) malloc(triangleSize * sizeof(int));
    memcpy(dp, triangle[triangleSize - 1], triangleSize * sizeof(int));

    for (int i = triangleSize - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j)
            dp[j] = MIN(dp[j], dp[j + 1]) + triangle[i][j];
    }
    int ret = dp[0];
    free(dp);
    return ret;
}