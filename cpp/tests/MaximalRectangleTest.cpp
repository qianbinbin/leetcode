#include "MaximalRectangle.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaximalRectangle, Solution85_1) {
  auto S85_1 = Solution85_1();

  std::vector<std::vector<char>> Matrix1{{'1', '0', '1', '0', '0'},
                                         {'1', '0', '1', '1', '1'},
                                         {'1', '1', '1', '1', '1'},
                                         {'1', '0', '0', '1', '0'}};
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S85_1.maximalRectangle(Matrix1));

  std::vector<std::vector<char>> Matrix2{{'0'}};
  int const Expected2 = 0;
  EXPECT_EQ(Expected2, S85_1.maximalRectangle(Matrix2));

  std::vector<std::vector<char>> Matrix3{{'1'}};
  int const Expected3 = 1;
  EXPECT_EQ(Expected3, S85_1.maximalRectangle(Matrix3));
}

TEST(MaximalRectangle, Solution85_2) {
  auto S85_2 = Solution85_2();

  std::vector<std::vector<char>> Matrix1{{'1', '0', '1', '0', '0'},
                                         {'1', '0', '1', '1', '1'},
                                         {'1', '1', '1', '1', '1'},
                                         {'1', '0', '0', '1', '0'}};
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S85_2.maximalRectangle(Matrix1));

  std::vector<std::vector<char>> Matrix2{{'0'}};
  int const Expected2 = 0;
  EXPECT_EQ(Expected2, S85_2.maximalRectangle(Matrix2));

  std::vector<std::vector<char>> Matrix3{{'1'}};
  int const Expected3 = 1;
  EXPECT_EQ(Expected3, S85_2.maximalRectangle(Matrix3));
}
