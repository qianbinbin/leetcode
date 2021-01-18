#include "NQueensII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(NQueensII, Solution52_1) {
  EXPECT_EQ(2, Solution52_1().totalNQueens(4));
}