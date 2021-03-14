#include <gtest/gtest.h>

extern "C" {
#include "3sum_closest.h"
}

TEST(three_sum_closest_test, threeSumClosest_16_1) {
    int nums1[] = {-1, 2, 1, -4};
    int const numsSize1 = 4, target1 = 1, expected1 = 2;
    int actual1 = threeSumClosest_16_1(nums1, numsSize1, target1);
    EXPECT_EQ(expected1, actual1);
}
