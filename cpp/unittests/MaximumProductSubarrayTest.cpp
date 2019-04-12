#include "MaximumProductSubarray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaximumProductSubarray, Solution152_1) {
  std::vector<int> Nums1{2, 3, -2, 4};
  const int Expected1 = 6;
  EXPECT_EQ(Expected1, Solution152_1().maxProduct(Nums1));

  std::vector<int> Nums2{-2, 0, -1};
  const int Expected2 = 0;
  EXPECT_EQ(Expected2, Solution152_1().maxProduct(Nums2));
}