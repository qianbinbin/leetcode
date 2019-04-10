#include "Triangle.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Triangle, Solution120_1) {
  std::vector<std::vector<int>> Triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  const int Expected = 11;
  EXPECT_EQ(Expected, Solution120_1().minimumTotal(Triangle));
}
