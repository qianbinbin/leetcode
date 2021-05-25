package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * <p>The <strong>n-queens</strong> puzzle is the problem of placing <code>n</code> queens on an <code>n x n</code> chessboard such that no two queens attack each other.</p>
 *
 * <p>Given an integer <code>n</code>, return <em>all distinct solutions to the <strong>n-queens puzzle</strong></em>.</p>
 *
 * <p>Each solution contains a distinct board configuration of the n-queens' placement, where <code>'Q'</code> and <code>'.'</code> both indicate a queen and an empty space, respectively.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/queens.jpg" style="width: 600px; height: 268px;">
 * <pre><strong>Input:</strong> n = 4
 * <strong>Output:</strong> [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * <strong>Explanation:</strong> There exist two distinct solutions to the 4-queens puzzle as shown above
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 1
 * <strong>Output:</strong> [["Q"]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 9</code></li>
 * </ul>
 */
public class NQueens {
    public static class Solution1 {
        private void solveNQueens(char[][] board, int n, int i, List<List<String>> result,
                                  boolean[] col, boolean[] mainDiagonal, boolean[] antiDiagonal) {
            if (i == n) {
                List<String> solution = new ArrayList<>(n);
                for (char[] chars : board)
                    solution.add(new String(chars));
                result.add(solution);
                return;
            }
            for (int j = 0, d, a; j < n; ++j) {
                d = n - 1 + i - j;
                a = i + j;
                if (col[j] || mainDiagonal[d] || antiDiagonal[a]) continue;
                board[i][j] = 'Q';
                col[j] = true;
                mainDiagonal[d] = true;
                antiDiagonal[a] = true;
                solveNQueens(board, n, i + 1, result, col, mainDiagonal, antiDiagonal);
                col[j] = false;
                mainDiagonal[d] = false;
                antiDiagonal[a] = false;
                board[i][j] = '.';
            }
        }

        public List<List<String>> solveNQueens(int n) {
            List<List<String>> result = new ArrayList<>();
            char[][] board = new char[n][n];
            for (int i = 0; i < n; ++i) Arrays.fill(board[i], '.');
            solveNQueens(board, n, 0, result, new boolean[n], new boolean[2 * n - 1], new boolean[2 * n - 1]);
            return result;
        }
    }
}
