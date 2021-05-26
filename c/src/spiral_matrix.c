#include "spiral_matrix.h"

#include <stdbool.h>
#include <stdlib.h>

int *spiralOrder_54_1(int **matrix, int matrixSize, int *matrixColSize,
                      int *returnSize) {
    int const m = matrixSize, n = matrixColSize[0];
    int *ret = (int *) malloc(m * n * sizeof(int));
    *returnSize = 0;
    int left = 0, right = n - 1, top = 0, bottom = m - 1, i;
    while (true) {
        for (i = left; i <= right; ++i)
            ret[(*returnSize)++] = matrix[top][i];
        if (++top > bottom) break;
        for (i = top; i <= bottom; ++i)
            ret[(*returnSize)++] = matrix[i][right];
        if (left > --right) break;
        for (i = right; i >= left; --i)
            ret[(*returnSize)++] = matrix[bottom][i];
        if (top > --bottom) break;
        for (i = bottom; i >= top; --i)
            ret[(*returnSize)++] = matrix[i][left];
        if (++left > right) break;
    }
    return ret;
}
