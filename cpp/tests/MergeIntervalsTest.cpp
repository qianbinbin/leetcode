#include "MergeIntervals.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MergeIntervals, Solution56_1) {
  auto S56_1 = Solution56_1();

  std::vector<std::vector<int>> Intervals1{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  const std::vector<std::vector<int>> Expected1{{1, 6}, {8, 10}, {15, 18}};
  EXPECT_EQ(Expected1, S56_1.merge(Intervals1));

  std::vector<std::vector<int>> Intervals2{{1, 4}, {4, 5}};
  const std::vector<std::vector<int>> Expected2{{1, 5}};
  EXPECT_EQ(Expected2, S56_1.merge(Intervals2));
}