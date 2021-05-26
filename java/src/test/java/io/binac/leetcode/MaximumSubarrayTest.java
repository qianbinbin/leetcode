package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumSubarrayTest {
    private static final MaximumSubarray.Solution1 SOLUTION1 = new MaximumSubarray.Solution1();

    private final int[] NUMS1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    private final int EXPECTED1 = 6;

    private final int[] NUMS2 = {1};
    private final int EXPECTED2 = 1;

    private final int[] NUMS3 = {5, 4, -1, 7, 8};
    private final int EXPECTED3 = 23;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maxSubArray(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.maxSubArray(NUMS2));
        assertEquals(EXPECTED3, SOLUTION1.maxSubArray(NUMS3));
    }
}