#include "FindMinimumInRotatedSortedArrayII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FindMinimumInRotatedSortedArrayII, Solution154_1) {
  std::vector<int> Nums1{1, 3, 5};
  const int Expected1 = 1;
  EXPECT_EQ(Expected1, Solution154_1().findMin(Nums1));

  std::vector<int> Nums2{2, 2, 2, 0, 1};
  const int Expected2 = 0;
  EXPECT_EQ(Expected2, Solution154_1().findMin(Nums2));
}