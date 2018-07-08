package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LargestRectangleInHistogramTest {
    private final LargestRectangleInHistogram.Solution1 solution1 = new LargestRectangleInHistogram.Solution1();

    @Test
    void test1() {
        int heights[] = {2, 1, 5, 6, 2, 3};
        assertEquals(10, solution1.largestRectangleArea(heights));
    }
}