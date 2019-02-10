#include "3Sum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ThreeSum, Solution15_1) {
  std::vector<int> Nums{-1, 0, 1, 2, -1, -4};
  const std::vector<std::vector<int>> Expected{
      {-1, -1, 2},
      {-1, 0, 1},
  };
  EXPECT_EQ(Expected, Solution15_1().threeSum(Nums));
}