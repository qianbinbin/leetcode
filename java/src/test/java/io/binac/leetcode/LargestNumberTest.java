package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LargestNumberTest {
    private static final LargestNumber.Solution1 SOLUTION1 = new LargestNumber.Solution1();

    private final int[] NUMS1 = {10, 2};
    private final String EXPECTED1 = "210";

    private final int[] NUMS2 = {3, 30, 34, 5, 9};
    private final String EXPECTED2 = "9534330";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.largestNumber(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.largestNumber(NUMS2));
    }
}