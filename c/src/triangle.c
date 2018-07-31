#include "triangle.h"

#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal_120_1(int **triangle, int triangleRowSize, int *triangleColSizes) {
    if (triangle == NULL || triangleRowSize < 0 || triangleColSizes == NULL) return -1;
    if (triangleRowSize == 0) return 0;

    int *dp = (int *) malloc(triangleRowSize * sizeof(int));
    memcpy(dp, triangle[triangleRowSize - 1], triangleRowSize * sizeof(int));

    for (int i = triangleRowSize - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j)
            dp[j] = MIN(dp[j], dp[j + 1]) + triangle[i][j];
    }
    int ret = dp[0];
    free(dp);
    return ret;
}