#include <gtest/gtest.h>

extern "C" {
#include "climbing_stairs.h"
}

TEST(climbing_stairs_test, climbStairs_70_1) {
    EXPECT_EQ(2, climbStairs_70_1(2));
    EXPECT_EQ(3, climbStairs_70_1(3));
}

