#include "ContainerWithMostWater.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ContainerWithMostWater, Solution11_1) {
  std::vector<int> Height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  const int Expected = 49;
  EXPECT_EQ(Expected, Solution11_1().maxArea(Height));
}