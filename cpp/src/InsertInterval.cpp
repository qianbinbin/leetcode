#include "InsertInterval.h"

using namespace lcpp;

std::vector<std::vector<int>>
Solution57_1::insert(std::vector<std::vector<int>> &intervals,
                     std::vector<int> &newInterval) {
  std::vector<std::vector<int>> Result;
  auto less = [](const std::vector<int> &I1, const std::vector<int> &I2) {
    return I1[1] < I2[0];
  };
  auto Range =
      std::equal_range(intervals.begin(), intervals.end(), newInterval, less);
  auto LB = Range.first, UB = Range.second;
  Result.insert(Result.end(), intervals.begin(), LB);
  auto Merge = newInterval;
  for (auto I = LB; I != UB; ++I) {
    Merge[0] = std::min(Merge[0], (*I)[0]);
    Merge[1] = std::max(Merge[1], (*I)[1]);
  }
  Result.push_back(Merge);
  Result.insert(Result.end(), UB, intervals.end());
  return Result;
}
