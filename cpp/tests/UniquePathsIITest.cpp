#include "UniquePathsII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(UniquePathsII, Solution63_1) {
  auto S63_1 = Solution63_1();

  std::vector<std::vector<int>> ObstacleGrid1{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int const Expected1 = 2;
  EXPECT_EQ(Expected1, S63_1.uniquePathsWithObstacles(ObstacleGrid1));

  std::vector<std::vector<int>> ObstacleGrid2{{0, 1}, {0, 0}};
  int const Expected2 = 1;
  EXPECT_EQ(Expected2, S63_1.uniquePathsWithObstacles(ObstacleGrid2));
}