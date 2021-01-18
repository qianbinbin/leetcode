#include "SingleNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SingleNumber, Solution136_1) {
  std::vector<int> Nums1{2, 2, 1};
  const int Expected1 = 1;
  EXPECT_EQ(Expected1, Solution136_1().singleNumber(Nums1));

  std::vector<int> Nums2{4, 1, 2, 1, 2};
  const int Expected2 = 4;
  EXPECT_EQ(Expected2, Solution136_1().singleNumber(Nums2));
}