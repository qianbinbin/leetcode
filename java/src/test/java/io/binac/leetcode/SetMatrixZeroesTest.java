package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SetMatrixZeroesTest {
    private final SetMatrixZeroes.Solution1 solution1 = new SetMatrixZeroes.Solution1();

    @Test
    void test1() {
        int matrix1[][] = {
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1}
        };
        solution1.setZeroes(matrix1);
        int expected1[][] = {
                {1, 0, 1},
                {0, 0, 0},
                {1, 0, 1}
        };
        assertArrayEquals(expected1, matrix1);

        int matrix2[][] = {
                {0, 1, 2, 0},
                {3, 4, 5, 2},
                {1, 3, 1, 5}
        };
        solution1.setZeroes(matrix2);
        int expected2[][] = {
                {0, 0, 0, 0},
                {0, 4, 5, 0},
                {0, 3, 1, 0}
        };
        assertArrayEquals(expected2, matrix2);
    }
}