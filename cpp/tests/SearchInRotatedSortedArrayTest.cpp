#include "SearchInRotatedSortedArray.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchInRotatedSortedArray, Solution33_1) {
  std::vector<int> Nums{4, 5, 6, 7, 0, 1, 2};
  const int Target1 = 0, Expected1 = 4;
  EXPECT_EQ(Expected1, Solution33_1().search(Nums, Target1));

  const int Target2 = 3, Expected2 = -1;
  EXPECT_EQ(Expected2, Solution33_1().search(Nums, Target2));
}