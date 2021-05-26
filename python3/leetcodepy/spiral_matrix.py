"""
Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
"""
from typing import List


class Solution1:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        row = len(matrix)
        col = len(matrix[0])
        left, right, top, bottom = 0, col - 1, 0, row - 1
        while True:
            for j in range(left, right + 1):
                result.append(matrix[top][j])
            top += 1
            if top > bottom:
                break
            for i in range(top, bottom + 1):
                result.append(matrix[i][right])
            right -= 1
            if left > right:
                break
            for j in range(right, left - 1, -1):
                result.append(matrix[bottom][j])
            bottom -= 1
            if top > bottom:
                break
            for i in range(bottom, top - 1, -1):
                result.append(matrix[i][left])
            left += 1
            if left > right:
                break
        return result
