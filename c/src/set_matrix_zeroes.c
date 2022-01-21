#include "set_matrix_zeroes.h"

#include <stdbool.h>

void setZeroes_73_1(int **matrix, int matrixSize, int *matrixColSize) {
    int const m = matrixSize, n = matrixColSize[0];
    bool set_first_row = false, set_first_col = false;
    int i, j;
    for (i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            set_first_col = true;
            break;
        }
    }
    for (j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            set_first_row = true;
            break;
        }
    }

    for (i = 1; i < m; ++i) {
        for (j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (i = 1; i < m; ++i) {
        if (matrix[i][0] == 0)
            for (j = 1; j < n; ++j) matrix[i][j] = 0;
    }
    for (j = 1; j < n; ++j) {
        if (matrix[0][j] == 0)
            for (i = 1; i < m; ++i) matrix[i][j] = 0;
    }
    if (set_first_col)
        for (i = 0; i < m; ++i) matrix[i][0] = 0;
    if (set_first_row)
        for (j = 0; j < n; ++j) matrix[0][j] = 0;
}
