#include "MaximumSubarray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaximumSubarray, Solution53_1) {
  auto S53_1 = Solution53_1();

  std::vector<int> Nums1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S53_1.maxSubArray(Nums1));

  std::vector<int> Nums2{1};
  int const Expected2 = 1;
  EXPECT_EQ(Expected2, S53_1.maxSubArray(Nums2));

  std::vector<int> Nums3{5, 4, -1, 7, 8};
  int const Expected3 = 23;
  EXPECT_EQ(Expected3, S53_1.maxSubArray(Nums3));
}