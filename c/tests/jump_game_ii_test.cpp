#include <gtest/gtest.h>

extern "C" {
#include "jump_game_ii.h"
}

TEST(jump_game_ii_test, jump_45_1) {
    int nums1[] = {2, 3, 1, 1, 4};
    int const numsSize1 = 5, expected1 = 2;
    EXPECT_EQ(expected1, jump_45_1(nums1, numsSize1));

    int nums2[] = {2, 3, 0, 1, 4};
    int const numsSize2 = 5, expected2 = 2;
    EXPECT_EQ(expected2, jump_45_1(nums2, numsSize2));
}
