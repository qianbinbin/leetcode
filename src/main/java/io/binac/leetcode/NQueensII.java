package io.binac.leetcode;

import java.util.Arrays;
import java.util.concurrent.atomic.AtomicInteger;

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
        private void totalNQueens(int n, int row,
                                  AtomicInteger count, boolean column[], boolean mainDiagonal[], boolean antiDiagonal[]) {
            if (row == n) {
                count.incrementAndGet();
                return;
            }
            for (int j = 0; j < n; ++j) {
                final int main = -row + j + n - 1;
                final int anti = row + j;
                if (column[j] || mainDiagonal[main] || antiDiagonal[anti]) continue;
                column[j] = true;
                mainDiagonal[main] = true;
                antiDiagonal[anti] = true;
                totalNQueens(n, row + 1, count, column, mainDiagonal, antiDiagonal);
                column[j] = false;
                mainDiagonal[main] = false;
                antiDiagonal[anti] = false;
            }
        }

        public int totalNQueens(int n) {
            if (n < 1) throw new IllegalArgumentException("n must be positive");

            boolean column[] = new boolean[n];
            boolean mainDiagonal[] = new boolean[2 * n - 1];
            boolean antiDiagonal[] = new boolean[2 * n - 1];
            AtomicInteger result = new AtomicInteger();
            totalNQueens(n, 0, result, column, mainDiagonal, antiDiagonal);
            return result.get();
        }
    }
}
