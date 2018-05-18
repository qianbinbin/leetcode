#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <set_matrix_zeroes.h>
}

TEST(leetcode_73, normal) {
    int nums[5][4] = {{0, 0, 0, 5},
                      {4, 3, 1, 4},
                      {0, 1, 1, 4},
                      {1, 2, 1, 3},
                      {0, 0, 1, 1}};
    int **matrix = (int **) malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; ++i) {
        matrix[i] = (int *) malloc(4 * sizeof(int));
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = nums[i][j];
        }
    }
    for (int i = 0; i < 5; ++i) {
        array_print(matrix[i], 4);
    }
    printf("\n");

    setZeroes_73(matrix, 5, 4);
    for (int i = 0; i < 5; ++i) {
        array_print(matrix[i], 4);
        free(matrix[i]);
    }
    free(matrix);
}
