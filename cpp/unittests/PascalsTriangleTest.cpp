#include "PascalsTriangle.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PascalsTriangle, Solution118_1) {
  const int NumRows = 5;
  const std::vector<std::vector<int>> Expected{
      {1},
      {1, 1},
      {1, 2, 1},
      {1, 3, 3, 1},
      {1, 4, 6, 4, 1}
  };
  EXPECT_EQ(Expected, Solution118_1().generate(NumRows));
}