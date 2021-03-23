#include <gtest/gtest.h>

extern "C" {
#include "search_in_rotated_sorted_array.h"
}

TEST(search_in_rotated_sorted_array_test, search_33_1) {
    int nums1[] = {4, 5, 6, 7, 0, 1, 2}, numsSize1 = 7;
    int const target1 = 0, expected1 = 4;
    EXPECT_EQ(expected1, search_33_1(nums1, numsSize1, target1));

    int nums2[] = {4, 5, 6, 7, 0, 1, 2}, numsSize2 = 7;
    int const target2 = 3, expected2 = -1;
    EXPECT_EQ(expected2, search_33_1(nums2, numsSize2, target2));

    int nums3[] = {1}, numsSize3 = 1;
    int const target3 = 0, expected3 = -1;
    EXPECT_EQ(expected3, search_33_1(nums3, numsSize3, target3));
}
