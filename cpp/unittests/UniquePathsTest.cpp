#include "UniquePaths.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(UniquePaths, Solution62_1) {
  EXPECT_EQ(3, Solution62_1().uniquePaths(3, 2));
  EXPECT_EQ(28, Solution62_1().uniquePaths(7, 3));
}