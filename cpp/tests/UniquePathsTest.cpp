#include "UniquePaths.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(UniquePaths, Solution62_1) {
  auto S62_1 = Solution62_1();

  EXPECT_EQ(28, S62_1.uniquePaths(3, 7));
  EXPECT_EQ(3, S62_1.uniquePaths(3, 2));
  EXPECT_EQ(28, S62_1.uniquePaths(7, 3));
  EXPECT_EQ(6, S62_1.uniquePaths(3, 3));
}

TEST(UniquePaths, Solution62_2) {
  auto S62_2 = Solution62_2();

  EXPECT_EQ(28, S62_2.uniquePaths(3, 7));
  EXPECT_EQ(3, S62_2.uniquePaths(3, 2));
  EXPECT_EQ(28, S62_2.uniquePaths(7, 3));
  EXPECT_EQ(6, S62_2.uniquePaths(3, 3));
}
