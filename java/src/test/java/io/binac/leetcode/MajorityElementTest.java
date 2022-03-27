package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MajorityElementTest {
    private static final MajorityElement.Solution1 SOLUTION1 = new MajorityElement.Solution1();

    private final int[] NUMS1 = {3, 2, 3};
    private final int EXPECTED1 = 3;

    private final int[] NUMS2 = {2, 2, 1, 1, 1, 2, 2};
    private final int EXPECTED2 = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.majorityElement(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.majorityElement(NUMS2));
    }
}