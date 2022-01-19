#include "rotate_image.h"

static void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void rotate_48_1(int **matrix, int matrixSize, int *matrixColSize) {
    int const n = matrixSize;
    for (int i = 0, j; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            swap(matrix[i] + j, matrix[j] + i);
        }
    }
    for (int i = 0, j, h = n / 2; i < n; ++i) {
        for (j = 0; j < h; ++j) {
            swap(matrix[i] + j, matrix[i] + n - 1 - j);
        }
    }
}
