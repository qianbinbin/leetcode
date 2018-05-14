#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <spiral-matrix.h>
}

TEST(leetcode_54, normal) {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};
    int *matrix[] = {row1, row2, row3};
    int *nums = spiralOrder_54(matrix, 3, 3);
    array_print(nums, 9);
    free(nums);
}
