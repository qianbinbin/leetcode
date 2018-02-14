#include <set-matrix-zeroes.h>
#include <stddef.h>
#include <stdbool.h>

void setZeroes_73(int **matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrixRowSize < 1 || matrixColSize < 1) return;

    bool first_row = false, first_col = false;
    for (int i = 0; i < matrixRowSize; ++i) {
        if (matrix[i][0] == 0) {
            first_col = true;
            break;
        }
    }
    for (int j = 0; j < matrixColSize; ++j) {
        if (matrix[0][j] == 0) {
            first_row = true;
            break;
        }
    }

    for (int i = 1; i < matrixRowSize; ++i) {
        for (int j = 1; j < matrixColSize; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrixRowSize; ++i) {
        for (int j = 1; j < matrixColSize; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (first_col) {
        for (int i = 0; i < matrixRowSize; ++i) {
            matrix[i][0] = 0;
        }
    }
    if (first_row) {
        for (int j = 0; j < matrixColSize; ++j) {
            matrix[0][j] = 0;
        }
    }
}
