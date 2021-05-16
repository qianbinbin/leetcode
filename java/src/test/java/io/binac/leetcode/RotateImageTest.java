package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RotateImageTest {
    private static final RotateImage.Solution1 SOLUTION1 = new RotateImage.Solution1();

    private final int[][] MATRIX1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    private final int[][] EXPECTED1 = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

    private final int[][] MATRIX2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    private final int[][] EXPECTED2 = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};

    private final int[][] MATRIX3 = {{1}};
    private final int[][] EXPECTED3 = {{1}};

    private final int[][] MATRIX4 = {{1, 2}, {3, 4}};
    private final int[][] EXPECTED4 = {{3, 1}, {4, 2}};

    @Test
    void test1() {
        SOLUTION1.rotate(MATRIX1);
        assertArrayEquals(EXPECTED1, MATRIX1);
        SOLUTION1.rotate(MATRIX2);
        assertArrayEquals(EXPECTED2, MATRIX2);
        SOLUTION1.rotate(MATRIX3);
        assertArrayEquals(EXPECTED3, MATRIX3);
        SOLUTION1.rotate(MATRIX4);
        assertArrayEquals(EXPECTED4, MATRIX4);
    }
}