#include "PascalsTriangle.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PascalsTriangle, Solution118_1) {
  auto S118_1 = Solution118_1();

  int const NumRows1 = 5;
  std::vector<std::vector<int>> const Expected1{
      {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
  EXPECT_EQ(Expected1, S118_1.generate(NumRows1));

  int const NumRows2 = 1;
  std::vector<std::vector<int>> const Expected2{{1}};
  EXPECT_EQ(Expected2, S118_1.generate(NumRows2));
}