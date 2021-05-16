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
    int *pMatrix1[3] = {matrix1[0], matrix1[1], matrix1[2]};
    int const matrixSize1 = 3;
    std::vector<std::vector<int>> expected1{{7, 4, 1},
                                            {8, 5, 2},
                                            {9, 6, 3}};
    rotate_48_1(pMatrix1, matrixSize1, NULL);
    for (int i = 0; i < matrixSize1; ++i)
        EXPECT_EQ(expected1[i],
                  std::vector<int>(matrix1[i], matrix1[i] + matrixSize1));

    int matrix2[][4] = {
            {5,  1,  9,  11},
            {2,  4,  8,  10},
            {13, 3,  6,  7},
            {15, 14, 12, 16}
    };
    int *pMatrix2[4] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};
    int const matrixSize2 = 4;
    std::vector<std::vector<int>> expected2{
            {15, 13, 2,  5},
            {14, 3,  4,  1},
            {12, 6,  8,  9},
            {16, 7,  10, 11}
    };
    rotate_48_1(pMatrix2, matrixSize2, NULL);
    for (int i = 0; i < matrixSize2; ++i)
        EXPECT_EQ(expected2[i],
                  std::vector<int>(matrix2[i], matrix2[i] + matrixSize2));

    int matrix3[][1] = {
            {1}
    };
    int *pMatrix3[1] = {matrix3[0]};
    int const matrixSize3 = 1;
    std::vector<std::vector<int>> expected3{{1}};
    rotate_48_1(pMatrix3, matrixSize3, NULL);
    for (int i = 0; i < matrixSize3; ++i)
        EXPECT_EQ(expected3[i],
                  std::vector<int>(matrix3[i], matrix3[i] + matrixSize3));

    int matrix4[][2] = {
            {1, 2},
            {3, 4}
    };
    int *pMatrix4[2] = {matrix4[0], matrix4[1]};
    int const matrixSize4 = 2;
    std::vector<std::vector<int>> expected4{{3, 1},
                                            {4, 2}};
    rotate_48_1(pMatrix4, matrixSize4, NULL);
    for (int i = 0; i < matrixSize4; ++i)
        EXPECT_EQ(expected4[i],
                  std::vector<int>(matrix4[i], matrix4[i] + matrixSize4));
}
