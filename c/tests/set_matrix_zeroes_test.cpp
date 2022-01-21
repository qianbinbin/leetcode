#include <gtest/gtest.h>

extern "C" {
#include "set_matrix_zeroes.h"
}

TEST(set_matrix_zeroes_test, setZeroes_73_1) {
    int matrix1[][3] = {{1, 1, 1},
                        {1, 0, 1},
                        {1, 1, 1}};
    int *m1[] = {matrix1[0], matrix1[1], matrix1[2]};
    int const matrixSize1 = 3;
    int matrixColSize1[] = {3, 3, 3};
    std::vector<std::vector<int>> expected1{{1, 0, 1},
                                            {0, 0, 0},
                                            {1, 0, 1}};
    setZeroes_73_1(m1, matrixSize1, matrixColSize1);
    for (int i = 0; i < matrixSize1; ++i)
        EXPECT_EQ(expected1[i],
                  std::vector<int>(m1[i], m1[i] + matrixColSize1[i]));

    int matrix2[][4] = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
    };
    int *m2[] = {matrix2[0], matrix2[1], matrix2[2]};
    int const matrixSize2 = 3;
    int matrixColSize2[] = {4, 4, 4};
    std::vector<std::vector<int>> expected2{{0, 0, 0, 0},
                                            {0, 4, 5, 0},
                                            {0, 3, 1, 0}};
    setZeroes_73_1(m2, matrixSize2, matrixColSize2);
    for (int i = 0; i < matrixSize2; ++i)
        EXPECT_EQ(expected2[i],
                  std::vector<int>(m2[i], m2[i] + matrixColSize2[i]));
}
