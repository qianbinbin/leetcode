#include "NQueensII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(NQueensII, Solution52_1) {
  auto S52_1 = Solution52_1();

  EXPECT_EQ(2, S52_1.totalNQueens(4));
  EXPECT_EQ(1, S52_1.totalNQueens(1));
}