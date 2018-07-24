package io.binac.leetcode;

/**
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 * <p>
 * <p>A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     X X X X
 *     X O O X
 *     X X O X
 *     X O X X
 * </blockquote></pre>
 * After running your function, the board should be:
 * <blockquote><pre>
 *     X X X X
 *     X X X X
 *     X X X X
 *     X O X X
 * </blockquote></pre>
 * Explanation:
 * <p>
 * <p>Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */
public class SurroundedRegions {
    public static class Solution1 {
        private void mark(char[][] board, int i, int j, int row, int col) {
            if (board[i][j] == 'O') {
                board[i][j] = 'M';
                if (i > 0) mark(board, i - 1, j, row, col);
                if (i < row - 1) mark(board, i + 1, j, row, col);
                if (j > 0) mark(board, i, j - 1, row, col);
                if (j < col - 1) mark(board, i, j + 1, row, col);
            }
        }

        public void solve(char[][] board) {
            final int row = board.length;
            if (row == 0) return;
            final int col = board[0].length;
            if (col == 0) return;

            for (int i = 0; i < row; ++i) {
                mark(board, i, 0, row, col);
                if (col > 1) mark(board, i, col - 1, row, col);
            }
            for (int j = 0; j < col; ++j) {
                mark(board, 0, j, row, col);
                if (row > 1) mark(board, row - 1, j, row, col);
            }

            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (board[i][j] == 'O')
                        board[i][j] = 'X';
                    else if (board[i][j] == 'M')
                        board[i][j] = 'O';
                }
            }
        }
    }
}
