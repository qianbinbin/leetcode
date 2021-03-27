package io.binac.leetcode;

/**
 * <p>Write a program to solve a Sudoku puzzle by filling the empty cells.</p>
 *
 * <p>A&nbsp;sudoku solution must satisfy <strong>all of&nbsp;the following rules</strong>:</p>
 *
 * <ol>
 * 	<li>Each of the digits&nbsp;<code>1-9</code> must occur exactly&nbsp;once in each row.</li>
 * 	<li>Each of the digits&nbsp;<code>1-9</code>&nbsp;must occur&nbsp;exactly once in each column.</li>
 * 	<li>Each of the digits&nbsp;<code>1-9</code> must occur exactly once in each of the 9 <code>3x3</code> sub-boxes of the grid.</li>
 * </ol>
 *
 * <p>The <code>'.'</code> character indicates empty cells.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="height:250px; width:250px">
 * <pre><strong>Input:</strong> board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * <strong>Output:</strong> [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * <strong>Explanation:</strong>&nbsp;The input board is shown above and the only valid solution is shown below:
 *
 * <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png" style="height:250px; width:250px">
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>board.length == 9</code></li>
 * 	<li><code>board[i].length == 9</code></li>
 * 	<li><code>board[i][j]</code> is a digit or <code>'.'</code>.</li>
 * 	<li>It is <strong>guaranteed</strong> that the input board has only one solution.</li>
 * </ul>
 */
public class SudokuSolver {
    public static class Solution1 {
        private boolean solve(char[][] board, int row, boolean[][] rowUsed, boolean[][] colUsed, boolean[][] blockUsed) {
            for (int col, block, num; row < 9; ++row) {
                for (col = 0; col < 9; ++col) {
                    if (board[row][col] != '.') continue;
                    block = row / 3 * 3 + col / 3;
                    for (num = 0; num < 9; ++num) {
                        if (rowUsed[row][num] || colUsed[col][num] || blockUsed[block][num])
                            continue;
                        board[row][col] = (char) (num + '1');
                        rowUsed[row][num] = true;
                        colUsed[col][num] = true;
                        blockUsed[block][num] = true;
                        if (solve(board, row, rowUsed, colUsed, blockUsed))
                            return true;
                        rowUsed[row][num] = false;
                        colUsed[col][num] = false;
                        blockUsed[block][num] = false;
                    }
                    board[row][col] = '.';
                    return false;
                }
            }
            return true;
        }

        public void solveSudoku(char[][] board) {
            boolean[][] rowUsed = new boolean[9][9];
            boolean[][] colUsed = new boolean[9][9];
            boolean[][] blockUsed = new boolean[9][9];
            for (int row = 0, col, block, num; row < 9; ++row) {
                for (col = 0; col < 9; ++col) {
                    if (board[row][col] == '.') continue;
                    block = row / 3 * 3 + col / 3;
                    num = board[row][col] - '1';
                    rowUsed[row][num] = true;
                    colUsed[col][num] = true;
                    blockUsed[block][num] = true;
                }
            }
            solve(board, 0, rowUsed, colUsed, blockUsed);
        }
    }
}
