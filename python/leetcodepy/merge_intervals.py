"""
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
"""
from typing import List

from .utils import Interval


class Solution1:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        result = []
        if not intervals:
            return result
        ordered = sorted(intervals, key=lambda i: i.start)
        pre = Interval(ordered[0].start, ordered[0].end)
        result.append(pre)
        for i in range(1, len(ordered)):
            if pre.end >= ordered[i].start:
                pre.end = max(pre.end, ordered[i].end)
            else:
                pre = Interval(ordered[i].start, ordered[i].end)
                result.append(pre)
        return result
