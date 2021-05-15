#include "PermutationsII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PermutationsII, Solution47_1) {
  auto S47_1 = Solution47_1();

  std::vector<int> Nums1{1, 1, 2};
  std::vector<std::vector<int>> const Expected1{
      {1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
  EXPECT_EQ(Expected1, S47_1.permuteUnique(Nums1));

  std::vector<int> Nums2{1, 2, 3};
  std::vector<std::vector<int>> const Expected2{
      {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  EXPECT_EQ(Expected2, S47_1.permuteUnique(Nums2));
}