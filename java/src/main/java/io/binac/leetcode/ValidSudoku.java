package io.binac.leetcode;

import java.util.Arrays;

/**
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * <p>
 * <p>Each row must contain the digits 1-9 without repetition.
 * <p>Each column must contain the digits 1-9 without repetition.
 * <p>Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * <p>
 * <p>https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
 * <p>A partially filled sudoku which is valid.
 * <p>
 * <p>The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     [
 *       ["5","3",".",".","7",".",".",".","."],
 *       ["6",".",".","1","9","5",".",".","."],
 *       [".","9","8",".",".",".",".","6","."],
 *       ["8",".",".",".","6",".",".",".","3"],
 *       ["4",".",".","8",".","3",".",".","1"],
 *       ["7",".",".",".","2",".",".",".","6"],
 *       [".","6",".",".",".",".","2","8","."],
 *       [".",".",".","4","1","9",".",".","5"],
 *       [".",".",".",".","8",".",".","7","9"]
 *     ]
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     [
 *       ["8","3",".",".","7",".",".",".","."],
 *       ["6",".",".","1","9","5",".",".","."],
 *       [".","9","8",".",".",".",".","6","."],
 *       ["8",".",".",".","6",".",".",".","3"],
 *       ["4",".",".","8",".","3",".",".","1"],
 *       ["7",".",".",".","2",".",".",".","6"],
 *       [".","6",".",".",".",".","2","8","."],
 *       [".",".",".","4","1","9",".",".","5"],
 *       [".",".",".",".","8",".",".","7","9"]
 *     ]
 *     Output: false
 *     Explanation: Same as Example 1, except with the 5 in the top left corner being
 *         modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * <p>Only the filled cells need to be validated according to the mentioned rules.
 * <p>The given board contain only digits 1-9 and the character '.'.
 * <p>The given board size is always 9x9.
 */
public class ValidSudoku {
    public static class Solution1 {
        public boolean isValidSudoku(char[][] board) {
            if (board.length != 9 || board[0].length != 9)
                throw new IllegalArgumentException();

            boolean rowUsed[][] = new boolean[9][9];
            boolean colUsed[][] = new boolean[9][9];
            boolean blockUsed[][] = new boolean[9][9];
            for (int row = 0; row < 9; ++row) {
                for (int col = 0; col < 9; ++col) {
                    if (board[row][col] == '.') continue;
                    final int num = board[row][col] - '1';
                    final int block = row / 3 * 3 + col / 3;
                    if (rowUsed[row][num] || colUsed[col][num] || blockUsed[block][num])
                        return false;
                    rowUsed[row][num] = true;
                    colUsed[col][num] = true;
                    blockUsed[block][num] = true;
                }
            }
            return true;
        }
    }
}
