#include "SearchInsertPosition.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchInsertPosition, Solution35_1) {
  std::vector<int> Nums{1, 3, 5, 6};
  const int Target1 = 5, Expected1 = 2;
  EXPECT_EQ(Expected1, Solution35_1().searchInsert(Nums, Target1));

  const int Target2 = 2, Expected2 = 1;
  EXPECT_EQ(Expected2, Solution35_1().searchInsert(Nums, Target2));

  const int Target3 = 7, Expected3 = 4;
  EXPECT_EQ(Expected3, Solution35_1().searchInsert(Nums, Target3));

  const int Target4 = 0, Expected4 = 0;
  EXPECT_EQ(Expected4, Solution35_1().searchInsert(Nums, Target4));
}