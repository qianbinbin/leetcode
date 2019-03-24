#include "InsertInterval.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(InsertInterval, Solution57_1) {
  std::vector<Interval> Intervals1{Interval(1, 3), Interval(6, 9)};
  const Interval NewInterval1(2, 5);
  const std::vector<Interval> Expected1{Interval(1, 5), Interval(6, 9)};
  EXPECT_EQ(Expected1, Solution57_1().insert(Intervals1, NewInterval1));

  std::vector<Interval> Intervals2{
      Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10),
      Interval(12, 16)
  };
  const Interval NewInterval2(4, 8);
  const std::vector<Interval> Expected2{
      Interval(1, 2), Interval(3, 10), Interval(12, 16)
  };
  EXPECT_EQ(Expected2, Solution57_1().insert(Intervals2, NewInterval2));
}