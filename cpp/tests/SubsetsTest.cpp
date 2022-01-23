#include "Subsets.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Subsets, Solution78_1) {
  auto S78_1 = Solution78_1();

  std::vector<int> Nums1{1, 2, 3};
  std::vector<std::vector<int>> const Expected1{
      {}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3},
  };
  EXPECT_EQ(Expected1, S78_1.subsets(Nums1));

  std::vector<int> Nums2{0};
  std::vector<std::vector<int>> const Expected2{{}, {0}};
  EXPECT_EQ(Expected2, S78_1.subsets(Nums2));
}