"""
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

https://leetcode.com/static/images/problemset/histogram.png

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

https://leetcode.com/static/images/problemset/histogram_area.png

The largest rectangle is shown in the shaded area, which has area = 10 unit.


Example:

Input: [2,1,5,6,2,3]
Output: 10
"""


class Solution1:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights.append(0)
        result = 0
        stack = []
        i = 0
        size = len(heights)
        while i < size:
            if not stack or heights[i] >= heights[stack[-1]]:
                stack.append(i)
                i += 1
            else:
                j = stack.pop()
                left = -1 if not stack else stack[-1]
                result = max(result, (i - left - 1) * heights[j])
        heights.pop()
        return result
