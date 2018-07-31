#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "spiral_matrix_ii.h"
}

TEST(spiral_matrix_ii_test, generateMatrix_59_1) {
    const int n = 3;
    int **matrix = generateMatrix_59_1(n);
    for (int i = 0; i < n; ++i) {
        array_print(matrix[i], n);
        free(matrix[i]);
    }
    free(matrix);
}
