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

from .utils import Interval


class Solution1:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        result = []
        size = len(intervals)
        i = 0
        while i < size and intervals[i].end < newInterval.start:
            result.append(Interval(intervals[i].start, intervals[i].end))
            i += 1
        merge = Interval(newInterval.start, newInterval.end)
        while i < size and merge.end >= intervals[i].start:
            merge.start = min(merge.start, intervals[i].start)
            merge.end = max(merge.end, intervals[i].end)
            i += 1
        result.append(merge)
        while i < size:
            result.append(Interval(intervals[i].start, intervals[i].end))
            i += 1
        return result
