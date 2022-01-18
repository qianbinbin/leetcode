#include "MinimumPathSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MinimumPathSum, Solution64_1) {
  auto S64_1 = Solution64_1();

  std::vector<std::vector<int>> Grid1{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  int const Expected1 = 7;
  EXPECT_EQ(Expected1, S64_1.minPathSum(Grid1));

  std::vector<std::vector<int>> Grid2{{1, 2, 3}, {4, 5, 6}};
  int const Expected2 = 12;
  EXPECT_EQ(Expected2, S64_1.minPathSum(Grid2));
}
