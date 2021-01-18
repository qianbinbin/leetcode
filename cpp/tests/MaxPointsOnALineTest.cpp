#include "MaxPointsOnALine.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaxPointsOnALine, Solution149_1) {
  std::vector<Point> Points1{Point(1, 1), Point(2, 2), Point(3, 3)};
  const int Expected1 = 3;
  EXPECT_EQ(Expected1, Solution149_1().maxPoints(Points1));

  std::vector<Point> Points2{
      Point(1, 1), Point(3, 2), Point(5, 3),
      Point(4, 1), Point(2, 3), Point(1, 4)
  };
  const int Expected2 = 4;
  EXPECT_EQ(Expected2, Solution149_1().maxPoints(Points2));
}