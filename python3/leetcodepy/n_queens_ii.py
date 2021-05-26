"""
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.



Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:

Input: n = 1
Output: 1


Constraints:

1 <= n <= 9
"""
from typing import List


class Solution1:
    def totalNQueens(self, n: int) -> int:
        result = [0]
        col_used = [False] * n
        diagonal_used = [False] * (2 * n - 1)
        anti_diagonal_used = [False] * (2 * n - 1)
        self.__total_n_queens(n, 0, col_used, diagonal_used, anti_diagonal_used, result)
        return result[0]

    def __total_n_queens(self, n: int, i: int,
                         col_used: List[bool], diagonal_used: List[bool], anti_diagonal_used: List[bool],
                         result: List[int]):
        if i == n:
            result[0] += 1
            return
        for j in range(n):
            diagonal, anti_diagonal = n - 1 - i + j, i + j
            if col_used[j] or diagonal_used[diagonal] or anti_diagonal_used[anti_diagonal]:
                continue
            col_used[j] = diagonal_used[diagonal] = anti_diagonal_used[anti_diagonal] = True
            self.__total_n_queens(n, i + 1, col_used, diagonal_used, anti_diagonal_used, result)
            col_used[j] = diagonal_used[diagonal] = anti_diagonal_used[anti_diagonal] = False
