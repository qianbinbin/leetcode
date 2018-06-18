#include "spiral_matrix.h"

#include <stdbool.h>
#include <stdlib.h>

int *spiralOrder_54_1(int **matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrixRowSize < 0 || matrixColSize < 0) return NULL;

    int *ret = (int *) malloc(matrixRowSize * matrixColSize * sizeof(int));
    if (matrixRowSize == 0 || matrixColSize == 0) return ret;

    int size = 0;
    int left = 0, right = matrixColSize - 1, top = 0, bottom = matrixRowSize - 1;
    while (true) {
        for (int i = left; i <= right; ++i) ret[size++] = matrix[top][i];
        if (++top > bottom) break;
        for (int i = top; i <= bottom; ++i) ret[size++] = matrix[i][right];
        if (left > --right) break;
        for (int i = right; i >= left; --i) ret[size++] = matrix[bottom][i];
        if (top > --bottom) break;
        for (int i = bottom; i >= top; --i) ret[size++] = matrix[i][left];
        if (++left > right) break;
    }
    return ret;
}
