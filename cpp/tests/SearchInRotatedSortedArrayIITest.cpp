#include "SearchInRotatedSortedArrayII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchInRotatedSortedArrayII, Solution_1) {
  auto S81_1 = Solution81_1();

  std::vector<int> Nums1{2, 5, 6, 0, 0, 1, 2};
  EXPECT_TRUE(S81_1.search(Nums1, 0));
  EXPECT_FALSE(S81_1.search(Nums1, 3));
}