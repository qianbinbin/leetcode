package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ThreeSumClosestTest {
    private final ThreeSumClosest.Solution1 solution1 = new ThreeSumClosest.Solution1();

    @Test
    void test1() {
        int nums[] = {-1, 2, 1, -4};
        assertEquals(2, solution1.threeSumClosest(nums, 1));
    }
}