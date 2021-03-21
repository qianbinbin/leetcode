#include "NextPermutation.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(NextPermutation, Solution31_1) {
  auto S31_1 = Solution31_1();

  std::vector<int> Nums1{1, 2, 3};
  std::vector<int> const Expected1{1, 3, 2};
  S31_1.nextPermutation(Nums1);
  EXPECT_EQ(Expected1, Nums1);

  std::vector<int> Nums2{3, 2, 1};
  std::vector<int> const Expected2{1, 2, 3};
  S31_1.nextPermutation(Nums2);
  EXPECT_EQ(Expected2, Nums2);

  std::vector<int> Nums3{1, 1, 5};
  std::vector<int> const Expected3{1, 5, 1};
  S31_1.nextPermutation(Nums3);
  EXPECT_EQ(Expected3, Nums3);

  std::vector<int> Nums4{1};
  std::vector<int> const Expected4{1};
  S31_1.nextPermutation(Nums4);
  EXPECT_EQ(Expected4, Nums4);
}