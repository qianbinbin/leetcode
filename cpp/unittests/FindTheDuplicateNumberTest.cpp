#include "FindTheDuplicateNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FindTheDuplicateNumber, Solution287_1) {
  std::vector<int> Nums1{1, 3, 4, 2, 2};
  const int Expected1 = 2;
  EXPECT_EQ(Expected1, Solution287_1().findDuplicate(Nums1));

  std::vector<int> Nums2{3, 1, 3, 4, 2};
  const int Expected2 = 3;
  EXPECT_EQ(Expected2, Solution287_1().findDuplicate(Nums2));
}