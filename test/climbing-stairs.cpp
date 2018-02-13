#include <gtest/gtest.h>

extern "C" {
#include <climbing-stairs.h>
}

TEST(leetcode_70, normal) {
    EXPECT_EQ(climbStairs_70(5), 8);
}

