#include "NumberOfIslands.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(NumberOfIslands, Solution200_1) {
  std::vector<std::vector<char>> Grid1{{'1', '1', '1', '1', '0'},
                                       {'1', '1', '0', '1', '0'},
                                       {'1', '1', '0', '0', '0'},
                                       {'0', '0', '0', '0', '0'}};
  const int Expected1 = 1;
  EXPECT_EQ(Expected1, Solution200_1().numIslands(Grid1));

  std::vector<std::vector<char>> Grid2{{'1', '1', '0', '0', '0'},
                                       {'1', '1', '0', '0', '0'},
                                       {'0', '0', '1', '0', '0'},
                                       {'0', '0', '0', '1', '1'}};
  const int Expected2 = 3;
  EXPECT_EQ(Expected2, Solution200_1().numIslands(Grid2));
}