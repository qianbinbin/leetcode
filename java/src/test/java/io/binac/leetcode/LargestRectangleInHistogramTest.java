package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LargestRectangleInHistogramTest {
    private static final LargestRectangleInHistogram.Solution1 SOLUTION1 = new LargestRectangleInHistogram.Solution1();

    private final int[] HEIGHTS1 = {2, 1, 5, 6, 2, 3};
    private final int EXPECTED1 = 10;

    private final int[] HEIGHTS2 = {2, 4};
    private final int EXPECTED2 = 4;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.largestRectangleArea(HEIGHTS1));
        assertEquals(EXPECTED2, SOLUTION1.largestRectangleArea(HEIGHTS2));
    }
}