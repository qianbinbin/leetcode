#include "FindFirstAndLastPositionOfElementInSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FindFirstAndLastPositionOfElementInSortedArray, Solution34_1) {
  std::vector<int> Nums{5, 7, 7, 8, 8, 10};
  const int Target1 = 8;
  const std::vector<int> Expected1{3, 4};
  EXPECT_EQ(Expected1, Solution34_1().searchRange(Nums, Target1));

  const int Target2 = 6;
  const std::vector<int> Expected2{-1, -1};
  EXPECT_EQ(Expected2, Solution34_1().searchRange(Nums, Target2));
}
