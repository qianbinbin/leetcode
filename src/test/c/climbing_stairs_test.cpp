#include <gtest/gtest.h>

extern "C" {
#include "climbing_stairs.h"
}

TEST(climbing_stairs_test, climbStairs_70_1) {
    EXPECT_EQ(climbStairs_70_1(2), 2);
    EXPECT_EQ(climbStairs_70_1(3), 3);
}

