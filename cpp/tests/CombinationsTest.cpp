#include "Combinations.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Combinations, Solution77_1) {
  const int N = 4, K = 2;
  const std::vector<std::vector<int>> Expected{
      {1, 2},
      {1, 3},
      {1, 4},
      {2, 3},
      {2, 4},
      {3, 4}
  };
  EXPECT_EQ(Expected, Solution77_1().combine(N, K));
}