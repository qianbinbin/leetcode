#include "SingleNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SingleNumber, Solution136_1) {
  auto S136_1 = Solution136_1();

  std::vector<int> Nums1{2, 2, 1};
  int const Expected1 = 1;
  EXPECT_EQ(Expected1, S136_1.singleNumber(Nums1));

  std::vector<int> Nums2{4, 1, 2, 1, 2};
  int const Expected2 = 4;
  EXPECT_EQ(Expected2, S136_1.singleNumber(Nums2));

  std::vector<int> Nums3{1};
  int const Expected3 = 1;
  EXPECT_EQ(Expected3, S136_1.singleNumber(Nums3));
}