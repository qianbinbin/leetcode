#include "MaximalSquare.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaximalSquare, Solution221_1) {
  std::vector<std::vector<char>> Matrix{{'1', '0', '1', '0', '0'},
                                        {'1', '0', '1', '1', '1'},
                                        {'1', '1', '1', '1', '1'},
                                        {'1', '0', '0', '1', '0'}};
  const int Expected = 4;
  EXPECT_EQ(Expected, Solution221_1().maximalSquare(Matrix));
}