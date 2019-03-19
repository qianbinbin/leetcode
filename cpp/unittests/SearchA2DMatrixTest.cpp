#include "SearchA2DMatrix.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchA2DMatrix, Solution74_1) {
  std::vector<std::vector<int>> Matrix{
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 50}
  };
  EXPECT_TRUE(Solution74_1().searchMatrix(Matrix, 3));
  EXPECT_FALSE(Solution74_1().searchMatrix(Matrix, 13));
}