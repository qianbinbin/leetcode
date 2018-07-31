#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "set_matrix_zeroes.h"
}

TEST(set_matrix_zeroes_test, setZeroes_73_1) {
    int nums1[][3] = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
    };
    int *matrix1[] = {nums1[0], nums1[1], nums1[2]};
    for (int i = 0; i < 3; ++i)
        array_print(matrix1[i], 3);
    setZeroes_73_1(matrix1, 3, 3);
    for (int i = 0; i < 3; ++i)
        array_print(matrix1[i], 3);
    puts("");

    int nums2[][4] = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
    };
    int *matrix2[] = {nums2[0], nums2[1], nums2[2]};
    for (int i = 0; i < 3; ++i)
        array_print(matrix2[i], 4);
    setZeroes_73_1(matrix2, 3, 4);
    for (int i = 0; i < 3; ++i)
        array_print(matrix2[i], 4);
}
