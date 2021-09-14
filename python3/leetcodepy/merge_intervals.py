"""
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
"""
from typing import List


class Solution1:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        result = []
        if not intervals:
            return result
        ordered = sorted(intervals, key=lambda a: a[0])
        pre = [ordered[0][0], ordered[0][1]]
        result.append(pre)
        for i in range(1, len(ordered)):
            if pre[1] >= ordered[i][0]:
                pre[1] = max(pre[1], ordered[i][1])
            else:
                pre = [ordered[i][0], ordered[i][1]]
                result.append(pre)
        return result
