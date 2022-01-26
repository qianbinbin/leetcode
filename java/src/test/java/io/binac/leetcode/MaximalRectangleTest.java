package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximalRectangleTest {
    private static final MaximalRectangle.Solution1 SOLUTION1 = new MaximalRectangle.Solution1();
    private static final MaximalRectangle.Solution2 SOLUTION2 = new MaximalRectangle.Solution2();

    private final char[][] MATRIX1 = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    private final int EXPECTED1 = 6;

    private final char[][] MATRIX2 = {{'0'}};
    private final int EXPECTED2 = 0;

    private final char[][] MATRIX3 = {{'1'}};
    private final int EXPECTED3 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maximalRectangle(MATRIX1));
        assertEquals(EXPECTED2, SOLUTION1.maximalRectangle(MATRIX2));
        assertEquals(EXPECTED3, SOLUTION1.maximalRectangle(MATRIX3));
    }


    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.maximalRectangle(MATRIX1));
        assertEquals(EXPECTED2, SOLUTION2.maximalRectangle(MATRIX2));
        assertEquals(EXPECTED3, SOLUTION2.maximalRectangle(MATRIX3));
    }
}