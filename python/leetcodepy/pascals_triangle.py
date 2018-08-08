"""
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
"""


class Solution1:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows < 0:
            raise ValueError("numRows must be a non-negative integer")
        result = []
        if numRows < 1:
            return result
        result.append([1])
        if numRows < 2:
            return result
        result.append([1, 1])
        for i in range(2, numRows):
            result.append([1] * (i + 1))
            for j in range(1, i):
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
        return result
