#include <gtest/gtest.h>

extern "C" {
#include "first_missing_positive.h"
}

TEST(first_missing_positive_test, firstMissingPositive_41_1) {
    int nums1[] = {1, 2, 0};
    int const numsSize1 = 3, expected1 = 3;
    EXPECT_EQ(expected1, firstMissingPositive_41_1(nums1, numsSize1));

    int nums2[] = {3, 4, -1, 1};
    int const numsSize2 = 4, expected2 = 2;
    EXPECT_EQ(expected2, firstMissingPositive_41_1(nums2, numsSize2));

    int nums3[] = {7, 8, 9, 11, 12};
    int const numsSize3 = 5, expected3 = 1;
    EXPECT_EQ(expected3, firstMissingPositive_41_1(nums3, numsSize3));
}
