package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ThreeSumClosestTest {
    private static final ThreeSumClosest.Solution1 SOLUTION1 = new ThreeSumClosest.Solution1();

    private final int[] NUMS1 = {-1, 2, 1, -4};
    private final int TARGET1 = 1;
    private final int EXPECTED1 = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.threeSumClosest(NUMS1, TARGET1));
    }
}