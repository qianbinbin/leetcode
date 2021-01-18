#include "TrappingRainWater.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(TrappingRainWater, Solution42_1) {
  std::vector<int> Height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  const int Expected = 6;
  EXPECT_EQ(Expected, Solution42_1().trap(Height));
}

TEST(TrappingRainWater, Solution42_2) {
  std::vector<int> Height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  const int Expected = 6;
  EXPECT_EQ(Expected, Solution42_2().trap(Height));
}
