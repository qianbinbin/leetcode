package io.binac.leetcode;

/**
 * Given a 2D board and a word, find if the word exists in the grid.
 * <p>
 * <p>The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     board =
 *     [
 *       ['A','B','C','E'],
 *       ['S','F','C','S'],
 *       ['A','D','E','E']
 *     ]
 *
 *     Given word = "ABCCED", return true.
 *     Given word = "SEE", return true.
 *     Given word = "ABCB", return false.
 * </blockquote></pre>
 */
public class WordSearch {
    public static class Solution1 {
        private boolean exist(char[][] board, int row, int col, int i, int j, boolean visited[][],
                              String word, int index) {
            if (index == word.length())
                return true;
            if (i < 0 || i >= row || j < 0 || j >= col ||
                    visited[i][j] || board[i][j] != word.charAt(index))
                return false;
            visited[i][j] = true;
            boolean result = exist(board, row, col, i - 1, j, visited, word, index + 1) ||
                    exist(board, row, col, i + 1, j, visited, word, index + 1) ||
                    exist(board, row, col, i, j - 1, visited, word, index + 1) ||
                    exist(board, row, col, i, j + 1, visited, word, index + 1);
            visited[i][j] = false;
            return result;
        }

        public boolean exist(char[][] board, String word) {
            final int row = board.length;
            if (row == 0) return false;
            final int col = board[0].length;
            if (word.isEmpty()) return true;

            boolean visited[][] = new boolean[row][col];
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (exist(board, row, col, i, j, visited, word, 0))
                        return true;
                }
            }
            return false;
        }
    }
}
