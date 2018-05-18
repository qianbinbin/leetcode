#include <rotate_image.h>
#include <stddef.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void rotate_48(int **matrix, int matrixRowSize, int *matrixColSizes) {
    if (matrix == NULL || matrixRowSize < 2 || *matrixColSizes < 2 || matrixRowSize != *matrixColSizes) return;
    int n = matrixRowSize;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(&matrix[i][j], &matrix[i][n - 1 - j]);
        }
    }
}
