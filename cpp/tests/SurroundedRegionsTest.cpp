#include "SurroundedRegions.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SurroundedRegions, Solution130_1) {
  auto S130_1 = Solution130_1();

  std::vector<std::vector<char>> Board1{{'X', 'X', 'X', 'X'},
                                        {'X', 'O', 'O', 'X'},
                                        {'X', 'X', 'O', 'X'},
                                        {'X', 'O', 'X', 'X'}};
  std::vector<std::vector<char>> const Expected1{{'X', 'X', 'X', 'X'},
                                                 {'X', 'X', 'X', 'X'},
                                                 {'X', 'X', 'X', 'X'},
                                                 {'X', 'O', 'X', 'X'}};
  S130_1.solve(Board1);
  EXPECT_EQ(Expected1, Board1);

  std::vector<std::vector<char>> Board2{{'X'}};
  std::vector<std::vector<char>> const Expected2{{'X'}};
  S130_1.solve(Board2);
  EXPECT_EQ(Expected2, Board2);
}