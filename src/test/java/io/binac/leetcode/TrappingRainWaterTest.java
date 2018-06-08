package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TrappingRainWaterTest {
    private final TrappingRainWater.Solution1 solution1 = new TrappingRainWater.Solution1();

    @Test
    void test1() {
        int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        assertEquals(6, solution1.trap(height));
    }
}