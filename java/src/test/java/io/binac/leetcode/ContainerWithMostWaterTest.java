package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ContainerWithMostWaterTest {
    private static final ContainerWithMostWater.Solution1 SOLUTION1 = new ContainerWithMostWater.Solution1();

    private final int[] HEIGHT1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    private final int EXPECTED1 = 49;

    private final int[] HEIGHT2 = {1, 1};
    private final int EXPECTED2 = 1;

    private final int[] HEIGHT3 = {4, 3, 2, 1, 4};
    private final int EXPECTED3 = 16;

    private final int[] HEIGHT4 = {1, 2, 1};
    private final int EXPECTED4 = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maxArea(HEIGHT1));
        assertEquals(EXPECTED2, SOLUTION1.maxArea(HEIGHT2));
        assertEquals(EXPECTED3, SOLUTION1.maxArea(HEIGHT3));
        assertEquals(EXPECTED4, SOLUTION1.maxArea(HEIGHT4));
    }
}