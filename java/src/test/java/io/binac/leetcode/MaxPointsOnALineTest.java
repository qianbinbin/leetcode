package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaxPointsOnALineTest {
    private static final MaxPointsOnALine.Solution1 SOLUTION1 = new MaxPointsOnALine.Solution1();

    private final int[][] POINTS1 = {{0, 0}, {1, 1}, {0, 0}};
    private final int EXPECTED1 = 3;

    private final int[][] POINTS2 = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    private final int EXPECTED2 = 4;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maxPoints(POINTS1));
        assertEquals(EXPECTED2, SOLUTION1.maxPoints(POINTS2));
    }
}