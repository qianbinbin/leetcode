#include "Permutations.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Permutations, Solution46_1) {
  std::vector<int> Nums{1, 2, 3};
  const std::vector<std::vector<int>> Expected{
      {1, 2, 3},
      {1, 3, 2},
      {2, 1, 3},
      {2, 3, 1},
      {3, 1, 2},
      {3, 2, 1}
  };
  EXPECT_EQ(Expected, Solution46_1().permute(Nums));
}
