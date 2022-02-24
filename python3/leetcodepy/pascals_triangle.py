"""
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif


Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]


Constraints:

1 <= numRows <= 30
"""
from typing import List


class Solution1:
    def generate(self, numRows: int) -> List[List[int]]:
        result = [[1]]
        for i in range(1, numRows):
            result.append([1] * (i + 1))
            for j in range(1, i):
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
        return result
