#include <gtest/gtest.h>

extern "C" {
#include "spiral_matrix.h"
}

TEST(spiral_matrix, spiralOrder_54_1) {
    int matrix1[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    int *m1[] = {matrix1[0], matrix1[1], matrix1[2]};
    int const matrixSize1 = 3;
    int matrixColSize1[] = {3, 3, 3};
    int returnSize1 = 0;
    std::vector<int> const expected1{1, 2, 3, 6, 9, 8, 7, 4, 5};
    int *actual1 = spiralOrder_54_1(m1, matrixSize1, matrixColSize1,
                                    &returnSize1);
    ASSERT_EQ(expected1.size(), returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));

    int matrix2[3][4] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };
    int *m2[] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};
    int const matrixSize2 = 3;
    int matrixColSize2[] = {4, 4, 4};
    int returnSize2 = 0;
    std::vector<int> const expected2{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    int *actual2 = spiralOrder_54_1(m2, matrixSize2, matrixColSize2,
                                    &returnSize2);
    ASSERT_EQ(expected2.size(), returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
}
