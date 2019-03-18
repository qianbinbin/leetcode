#include "MedianOfTwoSortedArrays.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MedianOfTwoSortedArrays, Solution4_1) {
  std::vector<int> Nums11{1, 3}, Nums12{2};
  const double Expected1 = 2.0;
  EXPECT_EQ(Expected1, Solution4_1().findMedianSortedArrays(Nums11, Nums12));

  std::vector<int> Nums21{1, 2}, Nums22{3, 4};
  const double Expected2 = 2.5;
  EXPECT_EQ(Expected2, Solution4_1().findMedianSortedArrays(Nums21, Nums22));
}