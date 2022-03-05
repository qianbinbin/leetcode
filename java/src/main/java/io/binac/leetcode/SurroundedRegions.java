package io.binac.leetcode;

/**
 * <p>Given an <code>m x n</code> matrix <code>board</code> containing <code>'X'</code> and <code>'O'</code>, <em>capture all regions that are 4-directionally&nbsp;surrounded by</em> <code>'X'</code>.</p>
 *
 * <p>A region is <strong>captured</strong> by flipping all <code>'O'</code>s into <code>'X'</code>s in that surrounded region.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg" style="width: 550px; height: 237px;">
 * <pre><strong>Input:</strong> board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * <strong>Output:</strong> [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * <strong>Explanation:</strong> Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> board = [["X"]]
 * <strong>Output:</strong> [["X"]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m == board.length</code></li>
 * 	<li><code>n == board[i].length</code></li>
 * 	<li><code>1 &lt;= m, n &lt;= 200</code></li>
 * 	<li><code>board[i][j]</code> is <code>'X'</code> or <code>'O'</code>.</li>
 * </ul>
 */
public class SurroundedRegions {
    public static class Solution1 {
        private void mark(char[][] board, int i, int j, int m, int n) {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
                return;
            board[i][j] = 'M';
            mark(board, i - 1, j, m, n);
            mark(board, i + 1, j, m, n);
            mark(board, i, j - 1, m, n);
            mark(board, i, j + 1, m, n);
        }

        public void solve(char[][] board) {
            final int m = board.length, n = board[0].length;

            for (int i = 0; i < m; ++i) {
                mark(board, i, 0, m, n);
                mark(board, i, n - 1, m, n);
            }
            for (int j = 0; j < n; ++j) {
                mark(board, 0, j, m, n);
                mark(board, m - 1, j, m, n);
            }

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    switch (board[i][j]) {
                        case 'O':
                            board[i][j] = 'X';
                            break;
                        case 'M':
                            board[i][j] = 'O';
                            break;
                    }
                }
            }
        }
    }
}
