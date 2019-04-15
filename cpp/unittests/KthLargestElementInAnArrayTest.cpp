#include "KthLargestElementInAnArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(KthLargestElementInAnArray, Solution215_1) {
  std::vector<int> Nums1{3, 2, 1, 5, 6, 4};
  const int K1 = 2, Expected1 = 5;
  EXPECT_EQ(Expected1, Solution215_1().findKthLargest(Nums1, K1));

  std::vector<int> Nums2{3, 2, 3, 1, 2, 4, 5, 5, 6};
  const int K2 = 4, Expected2 = 4;
  EXPECT_EQ(Expected2, Solution215_1().findKthLargest(Nums2, K2));
}