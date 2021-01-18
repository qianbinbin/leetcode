#include "MergeIntervals.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MergeIntervals, Solution56_1) {
  std::vector<Interval> Intervals1{
      Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)
  };
  const std::vector<Interval> Expected1{
      Interval(1, 6), Interval(8, 10), Interval(15, 18)
  };
  EXPECT_EQ(Expected1, Solution56_1().merge(Intervals1));

  std::vector<Interval> Intervals2{Interval(1, 4), Interval(4, 5)};
  const std::vector<Interval> Expected2{Interval(1, 5)};
  EXPECT_EQ(Expected2, Solution56_1().merge(Intervals2));
}