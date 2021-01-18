#include "UniquePathsII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(UniquePathsII, Solution63_1) {
  std::vector<std::vector<int>> ObstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  const int Expected = 2;
  EXPECT_EQ(Expected, Solution63_1().uniquePathsWithObstacles(ObstacleGrid));
}