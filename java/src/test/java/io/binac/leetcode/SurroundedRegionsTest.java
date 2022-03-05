package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SurroundedRegionsTest {
    private static final SurroundedRegions.Solution1 SOLUTION1 = new SurroundedRegions.Solution1();

    private char[][] getBOARD1() {
        return new char[][]{{'X', 'X', 'X', 'X'},
                {'X', 'O', 'O', 'X'},
                {'X', 'X', 'O', 'X'},
                {'X', 'O', 'X', 'X'}};
    }

    private final char[][] EXPECTED1 = {
            {'X', 'X', 'X', 'X'},
            {'X', 'X', 'X', 'X'},
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'X', 'X'}
    };

    private char[][] getBOARD2() {
        return new char[][]{{'X'}};
    }

    private final char[][] EXPECTED2 = {{'X'}};

    @Test
    void test1() {
        char[][] board1 = getBOARD1();
        SOLUTION1.solve(board1);
        assertArrayEquals(EXPECTED1, board1);

        char[][] board2 = getBOARD2();
        SOLUTION1.solve(board2);
        assertArrayEquals(EXPECTED2, board2);
    }
}