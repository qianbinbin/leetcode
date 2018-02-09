#include <gtest/gtest.h>

extern "C" {
#include <trapping-rain-water.h>
}

TEST(leetcode_42_1, normal) {
    int nums[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(trap_42_1(nums, 12), 6);
}

TEST(leetcode_42_2, normal) {
    int nums[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(trap_42_2(nums, 12), 6);
}
