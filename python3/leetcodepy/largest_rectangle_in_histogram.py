"""
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:
https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg

Input: heights = [2,4]
Output: 4


Constraints:

1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
"""
from typing import List


class Solution1:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        result = 0
        stack = []
        size = len(heights)
        for i in range(size):
            while stack and heights[i] <= heights[stack[-1]]:
                j = stack.pop()
                left = 0 if not stack else stack[-1] + 1
                result = max(result, heights[j] * (i - left))
            stack.append(i)
        heights.pop()
        return result
