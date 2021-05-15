#include "Permutations.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Permutations, Solution46_1) {
  auto S46_1 = Solution46_1();

  std::vector<int> Nums1{1, 2, 3};
  std::vector<std::vector<int>> const Expected1{
      {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  EXPECT_EQ(Expected1, S46_1.permute(Nums1));

  std::vector<int> Nums2{0, 1};
  std::vector<std::vector<int>> const Expected2{{0, 1}, {1, 0}};
  EXPECT_EQ(Expected2, S46_1.permute(Nums2));

  std::vector<int> Nums3{1};
  std::vector<std::vector<int>> const Expected3{{1}};
  EXPECT_EQ(Expected3, S46_1.permute(Nums3));
}
