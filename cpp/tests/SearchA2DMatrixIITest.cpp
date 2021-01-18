#include "SearchA2DMatrixII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SearchA2DMatrixII, Solution240_1) {
  std::vector<std::vector<int>> Matrix{{1, 4, 7, 11, 15},
                                       {2, 5, 8, 12, 19},
                                       {3, 6, 9, 16, 22},
                                       {10, 13, 14, 17, 24},
                                       {18, 21, 23, 26, 30}};
  EXPECT_TRUE(Solution240_1().searchMatrix(Matrix, 5));
  EXPECT_FALSE(Solution240_1().searchMatrix(Matrix, 20));
}