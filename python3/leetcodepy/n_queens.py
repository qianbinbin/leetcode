"""
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

https://leetcode.com/static/images/problemset/8-queens.png

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
"""
from typing import List


class Solution1:
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        if n < 1:
            raise ValueError
        row_used, col_used = [False] * n, [False] * n
        diagonal_used, anti_diagonal_used = [False] * (2 * n - 1), [False] * (2 * n - 1)
        result = []
        path = [['.'] * n for i in range(n)]
        self.solve_n_queens(n, 0, col_used, diagonal_used, anti_diagonal_used, result, path)
        return result

    def solve_n_queens(self, n: int, i: int,
                       col_used: List[bool], diagonal_used: List[bool], anti_diagonal_used: List[bool],
                       result: List[List[str]], path: List[List[str]]):
        if i == n:
            result.append([''.join(row) for row in path])
            return
        for j in range(n):
            diagonal, anti_diagonal = n - 1 + i - j, i + j
            if col_used[j] or diagonal_used[diagonal] or anti_diagonal_used[anti_diagonal]:
                continue
            col_used[j] = diagonal_used[diagonal] = anti_diagonal_used[anti_diagonal] = True
            path[i][j] = 'Q'
            self.solve_n_queens(n, i + 1, col_used, diagonal_used, anti_diagonal_used, result, path)
            path[i][j] = '.'
            col_used[j] = diagonal_used[diagonal] = anti_diagonal_used[anti_diagonal] = False
