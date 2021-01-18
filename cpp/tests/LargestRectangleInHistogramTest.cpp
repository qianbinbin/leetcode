#include "LargestRectangleInHistogram.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LargestRectangleInHistogram, Solution84_1) {
  std::vector<int> Heights{2, 1, 5, 6, 2, 3};
  const int Expected = 10;
  EXPECT_EQ(Expected, Solution84_1().largestRectangleArea(Heights));
}