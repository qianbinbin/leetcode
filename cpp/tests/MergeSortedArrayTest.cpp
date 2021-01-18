#include "MergeSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MergeSortedArray, Solution88_1) {
  std::vector<int> Nums1{1, 2, 3, 0, 0, 0}, Nums2{2, 5, 6};
  const int M = 3, N = 3;
  const std::vector<int> Expected{1, 2, 2, 3, 5, 6};
  Solution88_1().merge(Nums1, M, Nums2, N);
  EXPECT_EQ(Expected,
            std::vector<int>(Nums1.begin(), Nums1.begin() + Expected.size()));
}