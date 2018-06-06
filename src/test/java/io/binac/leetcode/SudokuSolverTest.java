package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SudokuSolverTest {
    private final SudokuSolver.Solution1 solution1 = new SudokuSolver.Solution1();

    @Test
    void test1() {
        char board[][] = {
                "53..7....".toCharArray(),
                "6..195...".toCharArray(),
                ".98....6.".toCharArray(),
                "8...6...3".toCharArray(),
                "4..8.3..1".toCharArray(),
                "7...2...6".toCharArray(),
                ".6....28.".toCharArray(),
                "...419..5".toCharArray(),
                "....8..79".toCharArray()
        };
        printSudoku(board);
        solution1.solveSudoku(board);
        System.out.println();
        printSudoku(board);
    }

    private void printSudoku(char[][] board) {
        for (int i = 0; i < 9; ++i) {
            System.out.print(board[i][0]);
            for (int j = 1; j < 9; ++j)
                System.out.print(" " + board[i][j]);
            System.out.println();
        }
    }
}