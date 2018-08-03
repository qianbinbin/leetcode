#include <gtest/gtest.h>

extern "C" {
#include "find_minimum_in_rotated_sorted_array.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

int nums1[] = {3, 4, 5, 1, 2};

int expected1 = 1;

int nums2[] = {4, 5, 6, 7, 0, 1, 2};

int expected2 = 0;

TEST(find_minimum_in_rotated_sorted_array_test, findMin_153_1) {
    EXPECT_EQ(findMin_153_1(nums1, ARR_SIZE(nums1)), expected1);
    EXPECT_EQ(findMin_153_1(nums2, ARR_SIZE(nums2)), expected2);
}
