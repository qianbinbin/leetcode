#include "SlidingWindowMaximum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SlidingWindowMaximum, Solution239_1) {
  std::vector<int> Nums{1, 3, -1, -3, 5, 3, 6, 7};
  const int K = 3;
  const std::vector<int> Expected{3, 3, 5, 5, 6, 7};
  EXPECT_EQ(Expected, Solution239_1().maxSlidingWindow(Nums, K));
}

TEST(SlidingWindowMaximum, Solution239_2) {
  std::vector<int> Nums{1, 3, -1, -3, 5, 3, 6, 7};
  const int K = 3;
  const std::vector<int> Expected{3, 3, 5, 5, 6, 7};
  EXPECT_EQ(Expected, Solution239_2().maxSlidingWindow(Nums, K));
}
