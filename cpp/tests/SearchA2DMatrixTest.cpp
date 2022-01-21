#include "SearchA2DMatrix.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchA2DMatrix, Solution74_1) {
  auto S74_1 = Solution74_1();

  std::vector<std::vector<int>> Matrix1{
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  int const Target1 = 3;
  EXPECT_TRUE(S74_1.searchMatrix(Matrix1, Target1));

  std::vector<std::vector<int>> Matrix2{
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  int const Target2 = 13;
  EXPECT_FALSE(S74_1.searchMatrix(Matrix1, Target2));
}