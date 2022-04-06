package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximalSquareTest {
    private static final MaximalSquare.Solution1 SOLUTION1 = new MaximalSquare.Solution1();

    private final char[][] MATRIX1 = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    private final int EXPECTED1 = 4;

    private final char[][] MATRIX2 = {{'0', '1'}, {'1', '0'}};
    private final int EXPECTED2 = 1;

    private final char[][] MATRIX3 = {{'0'}};
    private final int EXPECTED3 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maximalSquare(MATRIX1));
        assertEquals(EXPECTED2, SOLUTION1.maximalSquare(MATRIX2));
        assertEquals(EXPECTED3, SOLUTION1.maximalSquare(MATRIX3));
    }
}