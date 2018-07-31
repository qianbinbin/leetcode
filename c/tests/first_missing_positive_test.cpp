#include <gtest/gtest.h>

extern "C" {
#include "first_missing_positive.h"
}

TEST(first_missing_positive_test, firstMissingPositive_41_1) {
    int nums1[] = {1, 2, 0};
    EXPECT_EQ(firstMissingPositive_41_1(nums1, 3), 3);
    int nums2[] = {3, 4, -1, 1};
    EXPECT_EQ(firstMissingPositive_41_1(nums2, 4), 2);
    int nums3[] = {7, 8, 9, 11, 12};
    EXPECT_EQ(firstMissingPositive_41_1(nums3, 5), 1);
}
