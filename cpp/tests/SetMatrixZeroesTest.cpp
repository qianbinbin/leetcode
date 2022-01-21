#include "SetMatrixZeroes.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SetMatrixZeroes, Solution73_1) {
  auto S73_1 = Solution73_1();

  std::vector<std::vector<int>> Matrix1{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  const std::vector<std::vector<int>> Expected1{
      {1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  S73_1.setZeroes(Matrix1);
  EXPECT_EQ(Expected1, Matrix1);

  std::vector<std::vector<int>> Matrix2{
      {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  const std::vector<std::vector<int>> Expected2{
      {0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
  S73_1.setZeroes(Matrix2);
  EXPECT_EQ(Expected2, Matrix2);
}