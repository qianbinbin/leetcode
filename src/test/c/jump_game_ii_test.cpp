#include <gtest/gtest.h>

extern "C" {
#include "jump_game_ii.h"
}

TEST(jump_game_ii_test, jump_45_1) {
    int nums[] = {2, 3, 1, 1, 4};
    EXPECT_EQ(jump_45_1(nums, 5), 2);
}
