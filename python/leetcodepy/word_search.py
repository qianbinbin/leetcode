"""
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
"""
from typing import List


class Solution1:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board:
            return not word
        row, col = len(board), len(board[0])
        if col == 0:
            return not word
        visited = [[False] * col for i in range(row)]
        for i in range(row):
            for j in range(col):
                if self._exist(board, row, col, visited, i, j, 0, word):
                    return True
        return False

    def _exist(self, board: List[List[str]], row: int, col: int, visited: List[List[bool]],
               i: int, j: int, index: int, word: str) -> bool:
        if index == len(word):
            return True
        if i < 0 or i >= row or j < 0 or j >= col or visited[i][j] or word[index] != board[i][j]:
            return False
        visited[i][j] = True
        if self._exist(board, row, col, visited, i - 1, j, index + 1, word) \
                or self._exist(board, row, col, visited, i, j - 1, index + 1, word) \
                or self._exist(board, row, col, visited, i + 1, j, index + 1, word) \
                or self._exist(board, row, col, visited, i, j + 1, index + 1, word):
            return True
        visited[i][j] = False
        return False
