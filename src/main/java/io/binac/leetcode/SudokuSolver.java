package io.binac.leetcode;

/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * <p>
 * <p>A sudoku solution must satisfy all of the following rules:
 * <p>
 * <p>Each of the digits 1-9 must occur exactly once in each row.
 * <p>Each of the digits 1-9 must occur exactly once in each column.
 * <p>Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * <p>
 * <p>Empty cells are indicated by the character '.'.
 * <p>
 * <p>https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
 * <p>A sudoku puzzle...
 * <p>
 * <p>https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png
 * <p>...and its solution numbers marked in red.
 * <p>
 * <p>Note:
 * <p>
 * <p>The given board contain only digits 1-9 and the character '.'.
 * <p>You may assume that the given Sudoku puzzle will have a single unique solution.
 * <p>The given board size is always 9x9.
 */
public class SudokuSolver {
    public static class Solution1 {
        private boolean solve(char[][] board, int row, boolean[][] rowUsed, boolean[][] colUsed, boolean[][] blockUsed) {
            for (; row < 9; ++row) {
                for (int col = 0; col < 9; ++col) {
                    if (board[row][col] != '.') continue;
                    final int block = row / 3 * 3 + col / 3;
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        final int num = ch - '1';
                        if (rowUsed[row][num] || colUsed[col][num] || blockUsed[block][num])
                            continue;
                        board[row][col] = ch;
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
                    rowUsed[row][num] = true;
                    colUsed[col][num] = true;
                    blockUsed[block][num] = true;
                }
            }
            if (!solve(board, 0, rowUsed, colUsed, blockUsed))
                throw new IllegalArgumentException("no solution found");
        }
    }
}
