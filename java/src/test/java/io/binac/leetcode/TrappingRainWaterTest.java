package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TrappingRainWaterTest {
    private static final TrappingRainWater.Solution1 SOLUTION1 = new TrappingRainWater.Solution1();
    private static final TrappingRainWater.Solution2 SOLUTION2 = new TrappingRainWater.Solution2();
    private static final TrappingRainWater.Solution3 SOLUTION3 = new TrappingRainWater.Solution3();

    private final int[] HEIGHT1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    private final int EXPECTED1 = 6;

    private final int[] HEIGHT2 = {4, 2, 0, 3, 2, 5};
    private final int EXPECTED2 = 9;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.trap(HEIGHT1));
        assertEquals(EXPECTED2, SOLUTION1.trap(HEIGHT2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.trap(HEIGHT1));
        assertEquals(EXPECTED2, SOLUTION2.trap(HEIGHT2));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.trap(HEIGHT1));
        assertEquals(EXPECTED2, SOLUTION3.trap(HEIGHT2));
    }
}