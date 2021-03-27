"""
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The '.' character indicates empty cells.



Example 1:

https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
"""
from typing import List


class Solution1:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row_used = [[False for _ in range(9)] for _ in range(9)]
        col_used = [[False for _ in range(9)] for _ in range(9)]
        block_used = [[False for _ in range(9)] for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                b = i // 3 * 3 + j // 3
                n = int(board[i][j]) - 1
                row_used[i][n] = col_used[j][n] = block_used[b][n] = True
        self.solve_sudoku(board, 0, row_used, col_used, block_used)

    def solve_sudoku(self, board: List[List[str]], row: int,
                     row_used: List[List[bool]], col_used: List[List[bool]],
                     block_used: List[List[bool]]) -> bool:
        for i in range(row, 9):
            for j in range(0, 9):
                if board[i][j] != '.':
                    continue
                b = i // 3 * 3 + j // 3
                for n in range(9):
                    if row_used[i][n] or col_used[j][n] or block_used[b][n]:
                        continue
                    board[i][j] = str(n + 1)
                    row_used[i][n] = col_used[j][n] = block_used[b][n] = True
                    if self.solve_sudoku(board, i, row_used, col_used, block_used):
                        return True
                    row_used[i][n] = col_used[j][n] = block_used[b][n] = False
                board[i][j] = '.'
                return False
        return True
