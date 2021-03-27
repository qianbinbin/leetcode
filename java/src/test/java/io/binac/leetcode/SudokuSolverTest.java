package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SudokuSolverTest {
    private static final SudokuSolver.Solution1 SOLUTION1 = new SudokuSolver.Solution1();

    private final char[][] BOARD1 = {
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
    private final char[][] EXPECTED1 = {
            "534678912".toCharArray(),
            "672195348".toCharArray(),
            "198342567".toCharArray(),
            "859761423".toCharArray(),
            "426853791".toCharArray(),
            "713924856".toCharArray(),
            "961537284".toCharArray(),
            "287419635".toCharArray(),
            "345286179".toCharArray()
    };

    @Test
    void test1() {
        SOLUTION1.solveSudoku(BOARD1);
        assertArrayEquals(EXPECTED1, BOARD1);
    }
}