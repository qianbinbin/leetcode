package io.binac.leetcode;

/**
 * <p>Given an <code>m x n</code> grid of characters <code>board</code> and a string <code>word</code>, return <code>true</code> <em>if</em> <code>word</code> <em>exists in the grid</em>.</p>
 *
 * <p>The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word2.jpg" style="width: 322px; height: 242px;">
 * <pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg" style="width: 322px; height: 242px;">
 * <pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/word3.jpg" style="width: 322px; height: 242px;">
 * <pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m == board.length</code></li>
 * 	<li><code>n = board[i].length</code></li>
 * 	<li><code>1 &lt;= m, n &lt;= 6</code></li>
 * 	<li><code>1 &lt;= word.length &lt;= 15</code></li>
 * 	<li><code>board</code> and <code>word</code> consists of only lowercase and uppercase English letters.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong> Could you use search pruning to make your solution faster with a larger <code>board</code>?</p>
 */
public class WordSearch {
    public static class Solution1 {
        private boolean exist(char[][] board, int m, int n, int i, int j, boolean[][] visited,
                              String word, int index) {
            if (index == word.length())
                return true;
            if (i < 0 || i >= m || j < 0 || j >= n ||
                    visited[i][j] || board[i][j] != word.charAt(index))
                return false;
            visited[i][j] = true;
            boolean result = exist(board, m, n, i - 1, j, visited, word, index + 1) ||
                    exist(board, m, n, i + 1, j, visited, word, index + 1) ||
                    exist(board, m, n, i, j - 1, visited, word, index + 1) ||
                    exist(board, m, n, i, j + 1, visited, word, index + 1);
            visited[i][j] = false;
            return result;
        }

        public boolean exist(char[][] board, String word) {
            final int m = board.length, n = board[0].length;

            boolean[][] visited = new boolean[m][n];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (exist(board, m, n, i, j, visited, word, 0))
                        return true;
                }
            }
            return false;
        }
    }
}
