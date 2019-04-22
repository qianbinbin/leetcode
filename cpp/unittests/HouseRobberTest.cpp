#include "HouseRobber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(HouseRobber, Solution198_1) {
  std::vector<int> Nums1{1, 2, 3, 1};
  const int Expected1 = 4;
  EXPECT_EQ(Expected1, Solution198_1().rob(Nums1));

  std::vector<int> Nums2{2, 7, 9, 3, 1};
  const int Expected2 = 12;
  EXPECT_EQ(Expected2, Solution198_1().rob(Nums2));
}