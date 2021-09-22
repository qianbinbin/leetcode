"""
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
"""
from typing import List


class Solution1:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []
        size = len(intervals)
        i = 0
        while i < size and intervals[i][1] < newInterval[0]:
            result.append(intervals[i][:])
            i += 1
        merge = newInterval[:]
        while i < size and merge[1] >= intervals[i][0]:
            merge[0] = min(merge[0], intervals[i][0])
            merge[1] = max(merge[1], intervals[i][1])
            i += 1
        result.append(merge)
        while i < size:
            result.append(intervals[i][:])
            i += 1
        return result
