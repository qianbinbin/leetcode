#include "InsertInterval.h"

using namespace lcpp;

std::vector<Interval> Solution57_1::insert(std::vector<Interval> &intervals,
                                           Interval newInterval) {
  std::vector<Interval> Result;
  auto I = intervals.cbegin(), E = intervals.cend();
  for (; I != E && I->end < newInterval.start; ++I)
    Result.push_back(*I);
  Interval Merge = newInterval;
  for (; I != E && I->start <= newInterval.end; ++I) {
    if (I->start < Merge.start)
      Merge.start = I->start;
    if (I->end > Merge.end)
      Merge.end = I->end;
  }
  Result.push_back(Merge);
  for (; I != E; ++I)
    Result.push_back(*I);
  return Result;
}
