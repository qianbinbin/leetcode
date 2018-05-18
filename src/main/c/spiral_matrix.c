#include <spiral_matrix.h>
#include <stdlib.h>
#include <stdbool.h>

int *spiralOrder_54(int **matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrixRowSize < 0 || matrixColSize < 0) return NULL;

    int *ret = (int *) malloc(matrixRowSize * matrixColSize * sizeof(int));
    int size = 0;

    int left = 0, right = matrixColSize - 1, top = 0, bottom = matrixRowSize - 1;
    while (true) {
        for (int i = left; i <= right; ++i) ret[size++] = matrix[top][i];
        ++top;
        if (top > bottom) break;
        for (int i = top; i <= bottom; ++i) ret[size++] = matrix[i][right];
        --right;
        if (left > right) break;
        for (int i = right; i >= left; --i) ret[size++] = matrix[bottom][i];
        --bottom;
        if (top > bottom) break;
        for (int i = bottom; i >= top; --i) ret[size++] = matrix[i][left];
        ++left;
        if (left > right) break;
    }
    return ret;
}
