// Given an array of intervals where intervals[i] = [starti, endi], merge all
// overlapping intervals, and return an array of the non-overlapping intervals
// that cover all the intervals in the input.
//
//
//
// Example 1:
//
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
// Example 2:
//
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
//
// Constraints:
//
// 1 <= intervals.length <= 10^4
// intervals[i].length == 2
// 0 <= starti <= endi <= 10^4

#ifndef LEETCODECPP_MERGEINTERVALS_H
#define LEETCODECPP_MERGEINTERVALS_H

#include <vector>

namespace lcpp {

class Solution56_1 {
public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals);
};

} // namespace lcpp

#endif // LEETCODECPP_MERGEINTERVALS_H
