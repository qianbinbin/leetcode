#include <gtest/gtest.h>

extern "C" {
#include "3sum_closest.h"
}

TEST(three_sum_closest_test, threeSumClosest_16_1) {
    int nums[] = {-1, 2, 1, -4};
    int closest = threeSumClosest_16_1(nums, 4, 1);
    EXPECT_EQ(closest, 2);
}
