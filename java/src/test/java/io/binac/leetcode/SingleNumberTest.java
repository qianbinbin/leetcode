package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SingleNumberTest {
    private static final SingleNumber.Solution1 SOLUTION1 = new SingleNumber.Solution1();

    private final int[] NUMS1 = {2, 2, 1};
    private final int EXPECTED1 = 1;

    private final int[] NUMS2 = {4, 1, 2, 1, 2};
    private final int EXPECTED2 = 4;

    private final int[] NUMS3 = {1};
    private final int EXPECTED3 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.singleNumber(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.singleNumber(NUMS2));
        assertEquals(EXPECTED3, SOLUTION1.singleNumber(NUMS3));
    }
}