#include <gtest/gtest.h>

extern "C" {
#include <jump-game-ii.h>
}

TEST(leetcode_45_1, normal) {
    int nums1[] = {2, 3, 1, 1, 4};
    EXPECT_EQ(jump_45_1(nums1, 5), 2);
    int nums2[] = {0};
    EXPECT_EQ(jump_45_1(nums2, 1), 0);
}
