"""
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



Example 1:
https://assets.leetcode.com/uploads/2020/11/04/word2.jpg

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
https://assets.leetcode.com/uploads/2020/10/15/word3.jpg

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a larger board?
"""
from typing import List


class Solution1:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        visited = [[False] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if self._exist(board, m, n, visited, i, j, 0, word):
                    return True
        return False

    def _exist(self, board: List[List[str]], m: int, n: int, visited: List[List[bool]],
               i: int, j: int, index: int, word: str) -> bool:
        if index == len(word):
            return True
        if i < 0 or i >= m or j < 0 or j >= n or visited[i][j] or word[index] != board[i][j]:
            return False
        result = False
        visited[i][j] = True
        result = self._exist(board, m, n, visited, i - 1, j, index + 1, word) \
                 or self._exist(board, m, n, visited, i, j - 1, index + 1, word) \
                 or self._exist(board, m, n, visited, i + 1, j, index + 1, word) \
                 or self._exist(board, m, n, visited, i, j + 1, index + 1, word)
        visited[i][j] = False
        return result
