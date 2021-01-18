#include "PascalsTriangleII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PascalsTriangleII, Solution119_1) {
  const int RowIndex = 3;
  const std::vector<int> Expected{1, 3, 3, 1};
  EXPECT_EQ(Expected, Solution119_1().getRow(RowIndex));
}