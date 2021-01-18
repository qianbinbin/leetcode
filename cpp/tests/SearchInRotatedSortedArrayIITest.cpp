#include "SearchInRotatedSortedArrayII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchInRotatedSortedArrayII, Solution_1) {
  std::vector<int> Nums{2, 5, 6, 0, 0, 1, 2};
  EXPECT_TRUE(Solution81_1().search(Nums, 0));
  EXPECT_FALSE(Solution81_1().search(Nums, 3));
}