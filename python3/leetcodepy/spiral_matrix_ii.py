"""
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



Example 1:
https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 20
"""
from typing import List


class Solution1:
    def generateMatrix(self, n: int) -> List[List[int]]:
        result = [[0] * n for _ in range(n)]
        left, right, top, bottom = 0, n - 1, 0, n - 1
        count = 1
        while True:
            for j in range(left, right + 1):
                result[top][j] = count
                count += 1
            top += 1
            if top > bottom:
                break
            for i in range(top, bottom + 1):
                result[i][right] = count
                count += 1
            right -= 1
            if left > right:
                break
            for j in range(right, left - 1, -1):
                result[bottom][j] = count
                count += 1
            bottom -= 1
            if top > bottom:
                break
            for i in range(bottom, top - 1, -1):
                result[i][left] = count
                count += 1
            left += 1
            if left > right:
                break
        return result
