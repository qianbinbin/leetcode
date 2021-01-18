#include "Subsets.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Subsets, Solution78_1) {
  std::vector<int> Nums{1, 2, 3};
  const std::vector<std::vector<int>> Expected{
      {},
      {1},
      {1, 2},
      {1, 2, 3},
      {1, 3},
      {2},
      {2, 3},
      {3},
  };
  EXPECT_EQ(Expected, Solution77_1().subsets(Nums));
}