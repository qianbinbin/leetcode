#include "FindMinimumInRotatedSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FindMinimumInRotatedSortedArray, Solution153_1) {
  std::vector<int> Nums1{3, 4, 5, 1, 2};
  const int Expected1 = 1;
  EXPECT_EQ(Expected1, Solution153_1().findMin(Nums1));

  std::vector<int> Nums2{4, 5, 6, 7, 0, 1, 2};
  const int Expected2 = 0;
  EXPECT_EQ(Expected2, Solution153_1().findMin(Nums2));
}
