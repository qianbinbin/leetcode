#include "ClimbingStairs.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ClimbingStairs, Solution70_1) {
  EXPECT_EQ(2, Solution70_1().climbStairs(2));
  EXPECT_EQ(3, Solution70_1().climbStairs(3));
}