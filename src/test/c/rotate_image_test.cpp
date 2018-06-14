#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "rotate_image.h"
}

TEST(rotate_image_test, rotate_48_1) {
    int matrix1[][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    int *p_matrix1[3] = {matrix1[0], matrix1[1], matrix1[2]};
    const int row_size1 = 3;
    int col_sizes1[] = {3, 3, 3};
    for (int i = 0; i < row_size1; ++i)
        array_print(p_matrix1[i], col_sizes1[i]);
    printf("\n");

    rotate_48_1(p_matrix1, row_size1, col_sizes1);
    for (int i = 0; i < row_size1; ++i)
        array_print(p_matrix1[i], col_sizes1[i]);
    printf("\n");

    int matrix2[][4] = {
            {5, 1, 9, 11},
            {2, 4, 8, 10},
            {13, 3, 6, 7},
            {15, 14, 12, 16}
    };
    int *p_matrix2[4] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};
    const int row_size2 = 4;
    int col_sizes2[] = {4, 4, 4, 4};
    for (int i = 0; i < row_size2; ++i)
        array_print(p_matrix2[i], col_sizes2[i]);
    printf("\n");

    rotate_48_1(p_matrix2, row_size2, col_sizes2);
    for (int i = 0; i < row_size2; ++i)
        array_print(p_matrix2[i], col_sizes2[i]);
    printf("\n");
}
