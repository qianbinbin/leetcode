#include "3SumClosest.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ThreeSumClosest, Solution16_1) {
  std::vector<int> Nums{-1, 2, 1, -4};
  int Target = 1;
  const int Expected = 2;
  EXPECT_EQ(Expected, Solution16_1().threeSumClosest(Nums, Target));
}