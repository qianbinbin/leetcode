#include "MajorityElement.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MajorityElement, Solution169_1) {
  std::vector<int> Nums1{3, 2, 3};
  const int Expected1 = 3;
  EXPECT_EQ(Expected1, Solution169_1().majorityElement(Nums1));

  std::vector<int> Nums2{2, 2, 1, 1, 1, 2, 2};
  const int Expected2 = 2;
  EXPECT_EQ(Expected2, Solution169_1().majorityElement(Nums2));
}