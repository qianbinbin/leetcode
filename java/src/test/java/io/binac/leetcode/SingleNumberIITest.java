package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SingleNumberIITest {
    private static final SingleNumberII.Solution1 SOLUTION1 = new SingleNumberII.Solution1();

    private final int[] NUMS1 = {2, 2, 3, 2};
    private final int EXPECTED1 = 3;

    private final int[] NUMS2 = {0, 1, 0, 1, 0, 1, 99};
    private final int EXPECTED2 = 99;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.singleNumber(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.singleNumber(NUMS2));
    }
}