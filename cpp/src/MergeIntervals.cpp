#include "MergeIntervals.h"
#include <algorithm>

using namespace lcpp;

std::vector<Interval> Solution56_1::merge(std::vector<Interval> &intervals) {
  std::vector<Interval> Result;
  if (intervals.empty())
    return Result;
  std::sort(intervals.begin(), intervals.end(),
            [](const Interval &I1, const Interval &I2) {
              return I1.start < I2.start;
            });
  Result.push_back(intervals[0]);
  for (auto I = intervals.begin() + 1, E = intervals.end(); I != E; ++I) {
    auto &Last = Result.back(), &Cur = *I;
    if (Last.end >= Cur.start)
      Last.end = std::max(Last.end, Cur.end);
    else
      Result.push_back(Cur);
  }
  return Result;
}
