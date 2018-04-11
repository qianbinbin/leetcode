#include <gtest/gtest.h>

extern "C" {
#include <search-a-2d-matrix.h>
}

TEST(leetcode_74, normal) {
    int *matrix[3];
    int matrix0[] = {1, 3, 5, 7};
    int matrix1[] = {10, 11, 16, 20};
    int matrix2[] = {23, 30, 34, 50};
    matrix[0] = matrix0;
    matrix[1] = matrix1;
    matrix[2] = matrix2;
    EXPECT_TRUE(searchMatrix_74(matrix, 3, 4, 3));
}
