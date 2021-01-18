#include "MaximalRectangle.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaximalRectangle, Solution85_1) {
  std::vector<std::vector<char>> Matrix{
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}
  };
  const int Expected = 6;
  EXPECT_EQ(Expected, Solution85_1().maximalRectangle(Matrix));
}

TEST(MaximalRectangle, Solution85_2) {
  std::vector<std::vector<char>> Matrix{
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}
  };
  const int Expected = 6;
  EXPECT_EQ(Expected, Solution85_2().maximalRectangle(Matrix));
}
