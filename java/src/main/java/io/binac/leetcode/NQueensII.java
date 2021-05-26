package io.binac.leetcode;

/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * <p>
 * <p>https://leetcode.com/static/images/problemset/8-queens.png
 * <p>
 * <p>Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: 4
 *     Output: 2
 *     Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
 *     [
 *      [".Q..",  // Solution 1
 *       "...Q",
 *       "Q...",
 *       "..Q."],
 *
 *      ["..Q.",  // Solution 2
 *       "Q...",
 *       "...Q",
 *       ".Q.."]
 *     ]
 * </blockquote></pre>
 */
public class NQueensII {
    public static class Solution1 {
        private void totalNQueens(int n, int i, int[] count,
                                  boolean[] column, boolean[] mainDiagonal, boolean[] antiDiagonal) {
            if (i == n) {
                ++count[0];
                return;
            }
            for (int j = 0, d, a; j < n; ++j) {
                d = i - j + n - 1;
                a = i + j;
                if (column[j] || mainDiagonal[d] || antiDiagonal[a]) continue;
                column[j] = true;
                mainDiagonal[d] = true;
                antiDiagonal[a] = true;
                totalNQueens(n, i + 1, count, column, mainDiagonal, antiDiagonal);
                column[j] = false;
                mainDiagonal[d] = false;
                antiDiagonal[a] = false;
            }
        }

        public int totalNQueens(int n) {
            int[] result = new int[1];
            totalNQueens(n, 0, result, new boolean[n], new boolean[2 * n - 1], new boolean[2 * n - 1]);
            return result[0];
        }
    }
}
