#include "NQueens.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(NQueens, Solution51_1) {
  const int N = 4;
  const std::vector<std::vector<std::string>> Expected{
      {".Q..",
       "...Q",
       "Q...",
       "..Q."},
      {"..Q.",
       "Q...",
       "...Q",
       ".Q.."}
  };
  EXPECT_EQ(Expected, Solution51_1().solveNQueens(N));
}