#include "SpiralMatrixII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SpiralMatrixII, Solution59_1) {
  const int N = 3;
  std::vector<std::vector<int>> Expected{
      {1, 2, 3},
      {8, 9, 4},
      {7, 6, 5}
  };
  EXPECT_EQ(Expected, Solution59_1().generateMatrix(N));
}