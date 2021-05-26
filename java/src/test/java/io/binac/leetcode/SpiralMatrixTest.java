package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SpiralMatrixTest {
    private static final SpiralMatrix.Solution1 SOLUTION1 = new SpiralMatrix.Solution1();

    private final int[][] MATRIX1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    private final List<Integer> EXPECTED1 = Arrays.asList(1, 2, 3, 6, 9, 8, 7, 4, 5);

    private final int MATRIX2[][] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    private final List<Integer> EXPECTED2 = Arrays.asList(1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7);

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.spiralOrder(MATRIX1));
        assertEquals(EXPECTED2, SOLUTION1.spiralOrder(MATRIX2));
    }
}