package io.binac.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * <p>
 * <p>https://leetcode.com/static/images/problemset/8-queens.png
 * <p>
 * <p>Given an integer n, return all distinct solutions to the n-queens puzzle.
 * <p>
 * <p>Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 * <p>
 * Example:
 * <blockquote><pre>
 *     Input: 4
 *     Output: [
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
 *     Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
 * </blockquote></pre>
 */
public class NQueens {
    public static class Solution1 {
        private void solveNQueens(char board[][], int n, int row, List<List<String>> result,
                                  boolean col[], boolean mainDiagonal[], boolean antiDiagonal[]) {
            if (row == n) {
                List<String> solution = new ArrayList<>(n);
                for (char chars[] : board)
                    solution.add(new String(chars));
                result.add(solution);
                return;
            }
            for (int j = 0; j < n; ++j) {
                final int main = -row + j + n - 1;
                final int anti = row + j;
                if (col[j] || mainDiagonal[main] || antiDiagonal[anti]) continue;
                board[row][j] = 'Q';
                col[j] = true;
                mainDiagonal[main] = true;
                antiDiagonal[anti] = true;
                solveNQueens(board, n, row + 1, result, col, mainDiagonal, antiDiagonal);
                col[j] = false;
                mainDiagonal[main] = false;
                antiDiagonal[anti] = false;
                board[row][j] = '.';
            }
        }

        public List<List<String>> solveNQueens(int n) {
            if (n < 1)
                throw new IllegalArgumentException("n can't be less than 1");

            boolean col[] = new boolean[n];
            boolean mainDiagonal[] = new boolean[2 * n - 1];
            boolean antiDiagonal[] = new boolean[2 * n - 1];

            List<List<String>> result = new ArrayList<>();
            char board[][] = new char[n][n];
            for (int i = 0; i < n; ++i) Arrays.fill(board[i], '.');
            solveNQueens(board, n, 0, result, col, mainDiagonal, antiDiagonal);
            return result;
        }
    }
}
