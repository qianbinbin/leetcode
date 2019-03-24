#include "LongestConsecutiveSequence.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestConsecutiveSequence, Solution128_1) {
  std::vector<int> Nums{100, 4, 200, 1, 3, 2};
  const int Expected = 4;
  EXPECT_EQ(Expected, Solution128_1().longestConsecutive(Nums));
}

TEST(LongestConsecutiveSequence, Solution128_2) {
  std::vector<int> Nums{100, 4, 200, 1, 3, 2};
  const int Expected = 4;
  EXPECT_EQ(Expected, Solution128_2().longestConsecutive(Nums));
}
