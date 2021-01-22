#include <gtest/gtest.h>

extern "C" {
#include "median_of_two_sorted_arrays.h"
}

TEST(median_of_two_sorted_arrays_test, findMedianSortedArrays_4_1) {
    int nums11[] = {1, 3};
    int nums12[] = {2};
    EXPECT_DOUBLE_EQ(2, findMedianSortedArrays_4_1(nums11, 2, nums12, 1));

    int nums21[] = {1, 2};
    int nums22[] = {3, 4};
    EXPECT_DOUBLE_EQ(2.5, findMedianSortedArrays_4_1(nums21, 2, nums22, 2));

    int nums31[] = {0, 0};
    int nums32[] = {0, 0};
    EXPECT_DOUBLE_EQ(0, findMedianSortedArrays_4_1(nums31, 2, nums32, 2));

    int nums41[] = {};
    int nums42[] = {1};
    EXPECT_DOUBLE_EQ(1, findMedianSortedArrays_4_1(nums41, 0, nums42, 1));

    int nums51[] = {2};
    int nums52[] = {};
    EXPECT_DOUBLE_EQ(2, findMedianSortedArrays_4_1(nums51, 1, nums52, 0));
}
