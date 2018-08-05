#include <gtest/gtest.h>

extern "C" {
#include "find_minimum_in_rotated_sorted_array_ii.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

int nums1[] = {1, 3, 5};

int expected1 = 1;

int nums2[] = {2, 2, 2, 0, 1};

int expected2 = 0;

TEST(find_minimum_in_rotated_sorted_array_ii_test, findMin_154_1) {
    EXPECT_EQ(expected1, findMin_154_1(nums1, ARR_SIZE(nums1)));
    EXPECT_EQ(expected2, findMin_154_1(nums2, ARR_SIZE(nums2)));
}
