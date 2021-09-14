#include "MergeIntervals.h"
#include <algorithm>

using namespace lcpp;

std::vector<std::vector<int>>
Solution56_1::merge(std::vector<std::vector<int>> &intervals) {
  std::vector<std::vector<int>> Result;
  if (intervals.empty())
    return Result;
  std::sort(intervals.begin(), intervals.end());
  Result.push_back(intervals[0]);
  for (auto I = intervals.begin() + 1, E = intervals.end(); I != E; ++I) {
    auto &Last = Result.back(), &Cur = *I;
    if (Last[1] >= Cur[0])
      Last[1] = std::max(Last[1], Cur[1]);
    else
      Result.push_back(Cur);
  }
  return Result;
}
