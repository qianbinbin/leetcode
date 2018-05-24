package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ContainerWithMostWaterTest {
    private final ContainerWithMostWater.Solution1 solution1 = new ContainerWithMostWater.Solution1();

    @Test
    void test1() {
        int height[] = {1, 2, 1, 3, 2};
        assertEquals(6, solution1.maxArea(height));
    }
}