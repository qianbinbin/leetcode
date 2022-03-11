#include "SingleNumberII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SingleNumberII, Solution137_1) {
  auto S137_1 = Solution137_1();

  std::vector<int> Nums1{2, 2, 3, 2};
  int const Expected1 = 3;
  EXPECT_EQ(Expected1, S137_1.singleNumber(Nums1));

  std::vector<int> Nums2{0, 1, 0, 1, 0, 1, 99};
  int const Expected2 = 99;
  EXPECT_EQ(Expected2, S137_1.singleNumber(Nums2));
}