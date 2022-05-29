package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GameOfLifeTest {
    private static final GameOfLife.Solution1 SOLUTION1 = new GameOfLife.Solution1();

    private int[][] getBOARD1() {
        return new int[][]{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    }

    private final int[][] EXPECTED1 = {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};

    private int[][] getBOARD2() {
        return new int[][]{{1, 1}, {1, 0}};
    }

    private final int[][] EXPECTED2 = {{1, 1}, {1, 1}};

    @Test
    void test1() {
        int[][] board1 = getBOARD1();
        SOLUTION1.gameOfLife(board1);
        assertArrayEquals(EXPECTED1, board1);

        int[][] board2 = getBOARD2();
        SOLUTION1.gameOfLife(board2);
        assertArrayEquals(EXPECTED2, board2);
    }
}