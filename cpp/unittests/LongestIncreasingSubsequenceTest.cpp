#include "LongestIncreasingSubsequence.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestIncreasingSubsequence, Solution300_1) {
  std::vector<int> Nums{10, 9, 2, 5, 3, 7, 101, 18};
  const int Expected = 4;
  EXPECT_EQ(Expected, Solution300_1().lengthOfLIS(Nums));
}