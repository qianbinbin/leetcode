#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "spiral_matrix.h"
}

TEST(spiral_matrix, spiralOrder_54_1) {
    int matrix1[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    int *m1[] = {matrix1[0], matrix1[1], matrix1[2]};
    int *nums1 = spiralOrder_54_1(m1, 3, 3);
    array_print(nums1, 9);
    free(nums1);

    int matrix2[3][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    int *m2[] = {matrix2[0], matrix2[1], matrix2[2], matrix2[3]};
    int *nums2 = spiralOrder_54_1(m2, 3, 4);
    array_print(nums2, 12);
    free(nums2);
}
