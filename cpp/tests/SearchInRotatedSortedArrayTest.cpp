#include "SearchInRotatedSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchInRotatedSortedArray, Solution33_1) {
  auto S33_1 = Solution33_1();

  std::vector<int> Nums1{4, 5, 6, 7, 0, 1, 2};
  int const Target1 = 0, Expected1 = 4;
  EXPECT_EQ(Expected1, S33_1.search(Nums1, Target1));

  std::vector<int> Nums2{4, 5, 6, 7, 0, 1, 2};
  int const Target2 = 3, Expected2 = -1;
  EXPECT_EQ(Expected2, S33_1.search(Nums2, Target2));

  std::vector<int> Nums3{1};
  int const Target3 = 0, Expected3 = -1;
  EXPECT_EQ(Expected3, S33_1.search(Nums3, Target3));
}