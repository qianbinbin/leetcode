#include "SpiralMatrix.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SpiralMatrix, Solution54_1) {
  auto S54_1 = Solution54_1();

  std::vector<std::vector<int>> Matrix1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<int> const Expected1{1, 2, 3, 6, 9, 8, 7, 4, 5};
  EXPECT_EQ(Expected1, S54_1.spiralOrder(Matrix1));

  std::vector<std::vector<int>> Matrix2{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector<int> const Expected2{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
  EXPECT_EQ(Expected2, S54_1.spiralOrder(Matrix2));
}