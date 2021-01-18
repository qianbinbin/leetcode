#include "MaximumSubarray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaximumSubarray, Solution53_1) {
  std::vector<int> Nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  const int Expected = 6;
  EXPECT_EQ(Expected, Solution53_1().maxSubArray(Nums));
}