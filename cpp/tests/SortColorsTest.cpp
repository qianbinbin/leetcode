#include "SortColors.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SortColors, Solution75_1) {
  std::vector<int> Nums{2, 0, 2, 1, 1, 0};
  const std::vector<int> Expected{0, 0, 1, 1, 2, 2};
  Solution75_1().sortColors(Nums);
  EXPECT_EQ(Expected, Nums);
}

TEST(SortColors, Solution75_2) {
  std::vector<int> Nums{2, 0, 2, 1, 1, 0};
  const std::vector<int> Expected{0, 0, 1, 1, 2, 2};
  Solution75_2().sortColors(Nums);
  EXPECT_EQ(Expected, Nums);
}
