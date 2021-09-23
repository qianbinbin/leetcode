package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SpiralMatrixIITest {
    private static final SpiralMatrixII.Solution1 SOLUTION1 = new SpiralMatrixII.Solution1();

    private final int N1 = 3;
    private final int EXPECTED1[][] = {
            {1, 2, 3},
            {8, 9, 4},
            {7, 6, 5},
    };

    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.generateMatrix(N1));
    }
}