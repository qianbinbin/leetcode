#include <gtest/gtest.h>

extern "C" {
#include "maximal_rectangle.h"
}

TEST(maximal_rectangle_test, maximalRectangle_85_1) {
    char *matrix1[] = {"10100", "10111", "11111", "10010"};
    int const matrixSize1 = 4;
    int matrixColSize1[] = {5, 5, 5, 5};
    int const expected1 = 6;
    EXPECT_EQ(expected1,
              maximalRectangle_85_1(matrix1, matrixSize1, matrixColSize1));

    char *matrix2[] = {"0"};
    int const matrixSize2 = 1;
    int matrixColSize2[] = {1};
    int const expected2 = 0;
    EXPECT_EQ(expected2,
              maximalRectangle_85_1(matrix2, matrixSize2, matrixColSize2));

    char *matrix3[] = {"1"};
    int const matrixSize3 = 1;
    int matrixColSize3[] = {1};
    int const expected3 = 1;
    EXPECT_EQ(expected3,
              maximalRectangle_85_1(matrix3, matrixSize3, matrixColSize3));
}

TEST(maximal_rectangle_test, maximalRectangle_85_2) {
    char *matrix1[] = {"10100", "10111", "11111", "10010"};
    int const matrixSize1 = 4;
    int matrixColSize1[] = {5, 5, 5, 5};
    int const expected1 = 6;
    EXPECT_EQ(expected1,
              maximalRectangle_85_2(matrix1, matrixSize1, matrixColSize1));

    char *matrix2[] = {"0"};
    int const matrixSize2 = 1;
    int matrixColSize2[] = {1};
    int const expected2 = 0;
    EXPECT_EQ(expected2,
              maximalRectangle_85_2(matrix2, matrixSize2, matrixColSize2));

    char *matrix3[] = {"1"};
    int const matrixSize3 = 1;
    int matrixColSize3[] = {1};
    int const expected3 = 1;
    EXPECT_EQ(expected3,
              maximalRectangle_85_2(matrix3, matrixSize3, matrixColSize3));
}
