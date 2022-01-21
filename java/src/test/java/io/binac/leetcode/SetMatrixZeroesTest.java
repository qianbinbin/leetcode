package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SetMatrixZeroesTest {
    private static final SetMatrixZeroes.Solution1 SOLUTION1 = new SetMatrixZeroes.Solution1();

    private int[][] getMATRIX1() {
        return new int[][]{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    }

    private final int[][] EXPECTED1 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

    private int[][] getMATRIX2() {
        return new int[][]{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    }

    private final int[][] EXPECTED2 = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};

    @Test
    void test1() {
        int[][] matrix1 = getMATRIX1();
        SOLUTION1.setZeroes(matrix1);
        assertArrayEquals(EXPECTED1, matrix1);

        int[][] matrix2 = getMATRIX2();
        SOLUTION1.setZeroes(matrix2);
        assertArrayEquals(EXPECTED2, matrix2);
    }
}