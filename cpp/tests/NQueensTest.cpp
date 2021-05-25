#include "NQueens.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(NQueens, Solution51_1) {
  auto S51_1 = Solution51_1();

  int const N1 = 4;
  std::vector<std::vector<std::string>> const Expected1{
      {".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};
  EXPECT_EQ(Expected1, S51_1.solveNQueens(N1));

  int const N2 = 1;
  std::vector<std::vector<std::string>> const Expected2{{"Q"}};
  EXPECT_EQ(Expected2, S51_1.solveNQueens(N2));
}