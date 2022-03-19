#include "MaxPointsOnALine.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaxPointsOnALine, Solution149_1) {
  auto S149_1 = Solution149_1();

  std::vector<std::vector<int>> Points1{{1, 1}, {2, 2}, {3, 3}};
  int const Expected1 = 3;
  EXPECT_EQ(Expected1, S149_1.maxPoints(Points1));

  std::vector<std::vector<int>> Points2{{1, 1}, {3, 2}, {5, 3},
                                        {4, 1}, {2, 3}, {1, 4}};
  int const Expected2 = 4;
  EXPECT_EQ(Expected2, S149_1.maxPoints(Points2));
}