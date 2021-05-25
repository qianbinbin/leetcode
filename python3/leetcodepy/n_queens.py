"""
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



Example 1:

https://assets.leetcode.com/uploads/2020/11/13/queens.jpg
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]


Constraints:

1 <= n <= 9
"""
from typing import List


class Solution1:
    def solveNQueens(self, n: int) -> List[List[str]]:
        col_used = [False] * n
        diagonal_used, anti_diagonal_used = [False] * (2 * n - 1), [False] * (2 * n - 1)
        result = []
        path = [['.'] * n for _ in range(n)]
        self.solve_n_queens(n, 0, col_used, diagonal_used, anti_diagonal_used, result, path)
        return result

    def solve_n_queens(self, n: int, i: int,
                       col_used: List[bool], diagonal_used: List[bool], anti_diagonal_used: List[bool],
                       result: List[List[str]], path: List[List[str]]):
        if i == n:
            result.append([''.join(row) for row in path])
            return
        for j in range(n):
            d, a = n - 1 + i - j, i + j
            if col_used[j] or diagonal_used[d] or anti_diagonal_used[a]:
                continue
            col_used[j] = diagonal_used[d] = anti_diagonal_used[a] = True
            path[i][j] = 'Q'
            self.solve_n_queens(n, i + 1, col_used, diagonal_used, anti_diagonal_used, result, path)
            path[i][j] = '.'
            col_used[j] = diagonal_used[d] = anti_diagonal_used[a] = False
