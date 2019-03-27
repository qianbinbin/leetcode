#include "SurroundedRegions.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SurroundedRegions, Solution130_1) {
  std::vector<std::vector<char>> Board{
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'O', 'X'},
      {'X', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'}
  };
  const std::vector<std::vector<char>> Expected{
      {'X', 'X', 'X', 'X'},
      {'X', 'X', 'X', 'X'},
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'X', 'X'}
  };
  Solution130_1().solve(Board);
  EXPECT_EQ(Expected, Board);
}