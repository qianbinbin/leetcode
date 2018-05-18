#include <spiral_matrix_ii.h>
#include <stdbool.h>
#include <stdlib.h>

int **generateMatrix_59(int n) {
    if (n < 0) return NULL;

    int **ret = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) ret[i] = (int *) malloc(n * sizeof(int));

    int num = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    while (true) {
        for (int i = left; i <= right; ++i) ret[top][i] = num++;
        ++top;
        if (top > bottom) break;
        for (int i = top; i <= bottom; ++i) ret[i][right] = num++;
        --right;
        if (left > right) break;
        for (int i = right; i >= left; --i) ret[bottom][i] = num++;
        --bottom;
        if (top > bottom) break;
        for (int i = bottom; i >= top; --i) ret[i][left] = num++;
        ++left;
        if (left > right) break;
    }
    return ret;
}
