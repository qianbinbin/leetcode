#include "RotateImage.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RotateImage, Solution48_1) {
  auto S48_1 = Solution48_1();

  std::vector<std::vector<int>> Matrix1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> const Expected1{
      {7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
  S48_1.rotate(Matrix1);
  EXPECT_EQ(Expected1, Matrix1);

  std::vector<std::vector<int>> Matrix2{
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  std::vector<std::vector<int>> const Expected2{
      {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
  S48_1.rotate(Matrix2);
  EXPECT_EQ(Expected2, Matrix2);

  std::vector<std::vector<int>> Matrix3{{1}};
  std::vector<std::vector<int>> const Expected3{{1}};
  S48_1.rotate(Matrix3);
  EXPECT_EQ(Expected3, Matrix3);

  std::vector<std::vector<int>> Matrix4{{1, 2}, {3, 4}};
  std::vector<std::vector<int>> const Expected4{{3, 1}, {4, 2}};
  S48_1.rotate(Matrix4);
  EXPECT_EQ(Expected4, Matrix4);
}