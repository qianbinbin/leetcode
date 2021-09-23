#include "SpiralMatrixII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SpiralMatrixII, Solution59_1) {
  auto S59_1 = Solution59_1();

  int const N = 3;
  std::vector<std::vector<int>> const Expected{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
  EXPECT_EQ(Expected, S59_1.generateMatrix(N));
}