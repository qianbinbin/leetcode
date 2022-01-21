#include <gtest/gtest.h>

extern "C" {
#include "search_a_2d_matrix.h"
}

TEST(search_a_2d_matrix_test, searchMatrix_74_1) {
    int matrix1[][4] = {
            {1,  3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    int *m1[3] = {matrix1[0], matrix1[1], matrix1[2]};
    EXPECT_TRUE(searchMatrix_74_1(m1, 3, 4, 3));
    EXPECT_FALSE(searchMatrix_74_1(m1, 3, 4, 13));
}
