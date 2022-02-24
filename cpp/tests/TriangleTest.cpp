#include "Triangle.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Triangle, Solution120_1) {
  auto S120_1 = Solution120_1();

  std::vector<std::vector<int>> Triangle1{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int const Expected1 = 11;
  EXPECT_EQ(Expected1, S120_1.minimumTotal(Triangle1));

  std::vector<std::vector<int>> Triangle2{{-10}};
  int const Expected2 = -10;
  EXPECT_EQ(Expected2, S120_1.minimumTotal(Triangle2));
}
