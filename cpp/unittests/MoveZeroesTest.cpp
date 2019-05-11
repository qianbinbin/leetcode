#include "MoveZeroes.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MoveZeroes, Solution283_1) {
  std::vector<int> Nums{0, 1, 0, 3, 12};
  const std::vector<int> Expected{1, 3, 12, 0, 0};
  Solution283_1().moveZeroes(Nums);
  EXPECT_EQ(Expected, Nums);
}