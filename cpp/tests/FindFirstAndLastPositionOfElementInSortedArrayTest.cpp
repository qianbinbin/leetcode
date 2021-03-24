#include "FindFirstAndLastPositionOfElementInSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FindFirstAndLastPositionOfElementInSortedArray, Solution34_1) {
  auto S34_1 = Solution34_1();

  std::vector<int> Nums1{5, 7, 7, 8, 8, 10};
  int const Target1 = 8;
  std::vector<int> const Expected1{3, 4};
  EXPECT_EQ(Expected1, S34_1.searchRange(Nums1, Target1));

  std::vector<int> Nums2{5, 7, 7, 8, 8, 10};
  int const Target2 = 6;
  std::vector<int> const Expected2{-1, -1};
  EXPECT_EQ(Expected2, S34_1.searchRange(Nums2, Target2));

  std::vector<int> Nums3;
  int const Target3 = 0;
  std::vector<int> const Expected3{-1, -1};
  EXPECT_EQ(Expected3, S34_1.searchRange(Nums3, Target3));
}
