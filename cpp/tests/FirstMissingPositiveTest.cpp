#include "FirstMissingPositive.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FirstMissingPositive, Solution41_1) {
  std::vector<int> Nums1{1, 2, 0};
  const int Expected1 = 3;
  EXPECT_EQ(Expected1, Solution41_1().firstMissingPositive(Nums1));

  std::vector<int> Nums2{3, 4, -1, 1};
  const int Expected2 = 2;
  EXPECT_EQ(Expected2, Solution41_1().firstMissingPositive(Nums2));

  std::vector<int> Nums3{7, 8, 9, 11, 12};
  const int Expected3 = 1;
  EXPECT_EQ(Expected3, Solution41_1().firstMissingPositive(Nums3));
}