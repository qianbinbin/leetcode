package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HouseRobberTest {
    private static final HouseRobber.Solution1 SOLUTION1 = new HouseRobber.Solution1();

    private final int[] NUMS1 = {1, 2, 3, 1};
    private final int EXPECTED1 = 4;

    private final int[] NUMS2 = {2, 7, 9, 3, 1};
    private final int EXPECTED2 = 12;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.rob(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.rob(NUMS2));
    }
}