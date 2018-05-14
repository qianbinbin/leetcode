#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <spiral-matrix-ii.h>
}

TEST(leetcode_59, normal) {
    const int n = 3;
    int **matrix = generateMatrix_59(n);
    for (int i = 0; i < n; ++i) {
        array_print(matrix[i], n);
        free(matrix[i]);
    }
    free(matrix);
}
