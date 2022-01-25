#include "LargestRectangleInHistogram.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LargestRectangleInHistogram, Solution84_1) {
  auto S84_1 = Solution84_1();

  std::vector<int> Heights1{2, 1, 5, 6, 2, 3};
  int const Expected1 = 10;
  EXPECT_EQ(Expected1, S84_1.largestRectangleArea(Heights1));

  std::vector<int> Heights2{2, 4};
  int const Expected2 = 4;
  EXPECT_EQ(Expected2, S84_1.largestRectangleArea(Heights2));
}