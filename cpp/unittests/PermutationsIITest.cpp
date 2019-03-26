#include "PermutationsII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PermutationsII, Solution47_1) {
  std::vector<int> Nums{1, 1, 2};
  const std::vector<std::vector<int>> Expected{
      {1, 1, 2},
      {1, 2, 1},
      {2, 1, 1}
  };
  EXPECT_EQ(Expected, Solution47_1().permuteUnique(Nums));
}