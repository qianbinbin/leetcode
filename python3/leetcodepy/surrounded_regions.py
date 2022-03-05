"""
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Example 1:
https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

Example 2:

Input: board = [["X"]]
Output: [["X"]]


Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
"""
from typing import List


class Solution1:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        for i in range(m):
            self._mark(board, m, n, i, 0)
            if n != 1:
                self._mark(board, m, n, i, n - 1)
        for j in range(n):
            self._mark(board, m, n, 0, j)
            if m != 1:
                self._mark(board, m, n, m - 1, j)

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'M':
                    board[i][j] = 'O'

    def _mark(self, board: List[List[str]], m: int, n: int, i: int, j: int):
        if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != 'O':
            return
        board[i][j] = 'M'
        self._mark(board, m, n, i - 1, j)
        self._mark(board, m, n, i, j - 1)
        self._mark(board, m, n, i + 1, j)
        self._mark(board, m, n, i, j + 1)
