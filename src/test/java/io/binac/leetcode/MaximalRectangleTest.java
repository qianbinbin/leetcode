package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximalRectangleTest {
    private final MaximalRectangle.Solution1 solution1 = new MaximalRectangle.Solution1();

    @Test
    void test1() {
        char matrix[][] = {
                {'1', '0', '1', '0', '0'},
                {'1', '0', '1', '1', '1'},
                {'1', '1', '1', '1', '1'},
                {'1', '0', '0', '1', '0'}
        };
        assertEquals(6, solution1.maximalRectangle(matrix));
    }
}