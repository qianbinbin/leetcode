package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SpiralMatrixIITest {
    private final SpiralMatrixII.Solution1 solution1 = new SpiralMatrixII.Solution1();

    @Test
    void test1() {
        int expected[][] = {
                {1, 2, 3},
                {8, 9, 4},
                {7, 6, 5},
        };
        assertArrayEquals(expected, solution1.generateMatrix(3));
    }
}