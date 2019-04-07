#include "MinimumPathSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MinimumPathSum, Solution64_1) {
  std::vector<std::vector<int>> Grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  const int Expected = 7;
  EXPECT_EQ(Expected, Solution64_1().minPathSum(Grid));
}
