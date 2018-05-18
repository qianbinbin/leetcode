#include <gtest/gtest.h>

extern "C" {
#include <3sum_closest.h>
}

TEST(leetcode_16, normal) {
    int nums[] = {1, 2, 5, 10, 11};
    int closest = threeSumClosest_16(nums, 5, 12);
    EXPECT_EQ(closest, 13);
}
