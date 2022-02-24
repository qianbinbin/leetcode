#include "PascalsTriangleII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PascalsTriangleII, Solution119_1) {
  auto S119_1 = Solution119_1();

  int const RowIndex1 = 3;
  std::vector<int> const Expected1{1, 3, 3, 1};
  EXPECT_EQ(Expected1, S119_1.getRow(RowIndex1));

  int const RowIndex2 = 0;
  std::vector<int> const Expected2{1};
  EXPECT_EQ(Expected2, S119_1.getRow(RowIndex2));

  int const RowIndex3 = 1;
  std::vector<int> const Expected3{1, 1};
  EXPECT_EQ(Expected3, S119_1.getRow(RowIndex3));
}