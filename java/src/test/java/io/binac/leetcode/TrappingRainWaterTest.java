package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TrappingRainWaterTest {
    private final TrappingRainWater.Solution1 solution1 = new TrappingRainWater.Solution1();

    private final TrappingRainWater.Solution2 solution2 = new TrappingRainWater.Solution2();

    private final TrappingRainWater.Solution3 solution3 = new TrappingRainWater.Solution3();

    @Test
    void test1() {
        int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        assertEquals(6, solution1.trap(height));
    }

    @Test
    void test2() {
        int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        assertEquals(6, solution2.trap(height));
    }

    @Test
    void test3() {
        int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        assertEquals(6, solution3.trap(height));
    }
}