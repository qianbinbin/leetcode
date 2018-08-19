"""
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
"""
from typing import List


class Solution1:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        m, n = len(board), len(board[0])
        if n == 0:
            return
        for i in range(m):
            self.__mark(board, m, n, i, 0)
            if n != 1:
                self.__mark(board, m, n, i, n - 1)
        for j in range(n):
            self.__mark(board, m, n, 0, j)
            if m != 1:
                self.__mark(board, m, n, m - 1, j)

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'M':
                    board[i][j] = 'O'

    def __mark(self, board: List[List[str]], m: int, n: int, i: int, j: int):
        if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != 'O':
            return
        board[i][j] = 'M'
        self.__mark(board, m, n, i - 1, j)
        self.__mark(board, m, n, i, j - 1)
        self.__mark(board, m, n, i + 1, j)
        self.__mark(board, m, n, i, j + 1)
