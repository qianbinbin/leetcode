package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FindPeakElementTest {
    private static final FindPeakElement.Solution1 SOLUTION1 = new FindPeakElement.Solution1();

    private final int[] NUMS1 = {1, 2, 3, 1};
    private final int EXPECTED1 = 2;

    private final int[] NUMS2 = {1, 2, 1, 3, 5, 6, 4};
    private final int EXPECTED2 = 5;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.findPeakElement(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.findPeakElement(NUMS2));
    }
}