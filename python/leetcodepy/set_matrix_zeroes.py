"""
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
"""


class Solution1:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return
        if not matrix[0]:
            return
        row, col = len(matrix), len(matrix[0])
        set_first_row = False
        for j in range(col):
            if matrix[0][j] == 0:
                set_first_row = True
                break
        set_first_col = False
        for i in range(row):
            if matrix[i][0] == 0:
                set_first_col = True
                break

        for i in range(1, row):
            for j in range(1, col):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range(1, row):
            if matrix[i][0] == 0:
                for j in range(1, col):
                    matrix[i][j] = 0
        for j in range(1, col):
            if matrix[0][j] == 0:
                for i in range(1, row):
                    matrix[i][j] = 0
        if set_first_row:
            for j in range(col):
                matrix[0][j] = 0
        if set_first_col:
            for i in range(row):
                matrix[i][0] = 0
