package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximalRectangleTest {
    private final MaximalRectangle.Solution1 solution1 = new MaximalRectangle.Solution1();

    private final MaximalRectangle.Solution2 solution2 = new MaximalRectangle.Solution2();

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


    @Test
    void test2() {
        char matrix[][] = {
                {'1', '0', '1', '0', '0'},
                {'1', '0', '1', '1', '1'},
                {'1', '1', '1', '1', '1'},
                {'1', '0', '0', '1', '0'}
        };
        assertEquals(6, solution2.maximalRectangle(matrix));
    }
}