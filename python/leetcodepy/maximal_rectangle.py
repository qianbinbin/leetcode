"""
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
"""


class Solution1:
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix or not matrix[0]:
            return 0
        row, col = len(matrix), len(matrix[0])
        heights = [0] * col
        result = 0
        for i in range(row):
            stack = []
            for j in range(col):
                if matrix[i][j] == '0':
                    heights[j] = 0
                else:
                    heights[j] += 1
                while stack and heights[j] < heights[stack[-1]]:
                    k = stack.pop()
                    left = -1 if not stack else stack[-1]
                    result = max(result, (j - left - 1) * heights[k])
                stack.append(j)
            while stack:
                k = stack.pop()
                left = -1 if not stack else stack[-1]
                result = max(result, (col - left - 1) * heights[k])
        return result
