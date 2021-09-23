#include "spiral_matrix_ii.h"

#include <stdbool.h>
#include <stdlib.h>

int **generateMatrix_59_1(int n, int *returnSize, int **returnColumnSizes) {
    int **ret = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) ret[i] = (int *) malloc(n * sizeof(int));

    int num = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int i, j;
    while (true) {
        for (j = left; j <= right; ++j) ret[top][j] = num++;
        if (++top > bottom) break;
        for (i = top; i <= bottom; ++i) ret[i][right] = num++;
        if (left > --right) break;
        for (j = right; j >= left; --j) ret[bottom][j] = num++;
        if (top > --bottom) break;
        for (i = bottom; i >= top; --i) ret[i][left] = num++;
        if (++left > right) break;
    }
    *returnSize = n;
    *returnColumnSizes = (int *) malloc(n * sizeof(int));
    for (int k = 0; k < n; ++k)
        (*returnColumnSizes)[k] = n;
    return ret;
}
