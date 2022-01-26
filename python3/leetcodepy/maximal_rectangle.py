"""
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



Example 1:
https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1


Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
"""
from typing import List


class Solution1:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        heights = [0] * n
        left = [0] * n
        right = [n] * n
        result = 0
        for i in range(m):
            cur_left = 0
            for j in range(n):
                if matrix[i][j] == '0':
                    left[j] = 0
                    cur_left = j + 1
                    heights[j] = 0
                else:
                    left[j] = max(left[j], cur_left)
                    heights[j] += 1
            cur_right = n
            for j in range(n - 1, -1, -1):
                if matrix[i][j] == '0':
                    right[j] = n
                    cur_right = j
                else:
                    right[j] = min(right[j], cur_right)
                    result = max(result, heights[j] * (right[j] - left[j]))
        return result


class Solution2:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        heights = [0] * n
        result = 0
        for i in range(m):
            stack = []
            for j in range(n):
                heights[j] = 0 if matrix[i][j] == '0' else heights[j] + 1
                while stack and heights[j] <= heights[stack[-1]]:
                    k = stack.pop()
                    left = 0 if not stack else stack[-1] + 1
                    result = max(result, (j - left) * heights[k])
                stack.append(j)
            while stack:
                k = stack.pop()
                left = 0 if not stack else stack[-1] + 1
                result = max(result, (n - left) * heights[k])
        return result
