"""
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.

https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png

A sudoku puzzle...

https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png

...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
"""
from typing import Dict, List


class Solution1:
    __DIGITS = '123456789'

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        row_used = [{ch: False for ch in self.__DIGITS} for i in range(9)]
        col_used = [{ch: False for ch in self.__DIGITS} for i in range(9)]
        block_used = [{ch: False for ch in self.__DIGITS} for i in range(9)]
        for i in range(9):
            for j in range(9):
                ch = board[i][j]
                if ch == '.':
                    continue
                block = i // 3 * 3 + j // 3
                row_used[i][ch] = col_used[j][ch] = block_used[block][ch] = True
        if not self.solve_sudoku(board, 0, row_used, col_used, block_used):
            raise ValueError('invalid sudoku')

    def solve_sudoku(self, board: List[List[str]], row: int,
                     row_used: List[Dict[str, bool]], col_used: List[Dict[str, bool]],
                     block_used: List[Dict[str, bool]]) -> bool:
        for i in range(row, 9):
            for j in range(0, 9):
                ch = board[i][j]
                if ch != '.':
                    continue
                block = i // 3 * 3 + j // 3
                for c in self.__DIGITS:
                    if row_used[i][c] or col_used[j][c] or block_used[block][c]:
                        continue
                    board[i][j] = c
                    row_used[i][c] = col_used[j][c] = block_used[block][c] = True
                    if self.solve_sudoku(board, i, row_used, col_used, block_used):
                        return True
                    row_used[i][c] = col_used[j][c] = block_used[block][c] = False
                board[i][j] = '.'
                return False
        return True
