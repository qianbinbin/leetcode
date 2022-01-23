#include "Combinations.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(Combinations, Solution77_1) {
  auto S77_1 = Solution77_1();

  int const N1 = 4, K1 = 2;
  std::vector<std::vector<int>> const Expected1{{1, 2}, {1, 3}, {1, 4},
                                                {2, 3}, {2, 4}, {3, 4}};
  EXPECT_EQ(Expected1, S77_1.combine(N1, K1));

  int const N2 = 1, K2 = 1;
  std::vector<std::vector<int>> const Expected2{{1}};
  EXPECT_EQ(Expected2, S77_1.combine(N2, K2));
}