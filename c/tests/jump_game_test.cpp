#include <gtest/gtest.h>

extern "C" {
#include "jump_game.h"
}

TEST(jump_game, canJump_55_1) {
    int nums1[] = {2, 3, 1, 1, 4};
    EXPECT_TRUE(canJump_55_1(nums1, 5));
    int nums2[] = {3, 2, 1, 0, 4};
    EXPECT_FALSE(canJump_55_1(nums2, 5));
}

TEST(jump_game, canJump_55_2) {
    int nums1[] = {2, 3, 1, 1, 4};
    EXPECT_TRUE(canJump_55_2(nums1, 5));
    int nums2[] = {3, 2, 1, 0, 4};
    EXPECT_FALSE(canJump_55_2(nums2, 5));
}
