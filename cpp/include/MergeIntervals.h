// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
// Example 2:
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

#ifndef LEETCODECPP_MERGEINTERVALS_H
#define LEETCODECPP_MERGEINTERVALS_H

#include "Interval.h"
#include <vector>

namespace lcpp {

class Solution56_1 {
public:
  std::vector<Interval> merge(std::vector<Interval> &intervals);
};

}

#endif //LEETCODECPP_MERGEINTERVALS_H
