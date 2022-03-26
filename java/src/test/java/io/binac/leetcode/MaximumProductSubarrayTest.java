package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumProductSubarrayTest {
    private static final MaximumProductSubarray.Solution1 SOLUTION1 = new MaximumProductSubarray.Solution1();

    private final int[] NUMS1 = {2, 3, -2, 4};
    private final int EXPECTED1 = 6;

    private final int[] NUMS2 = {-2, 0, -1};
    private final int EXPECTED2 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maxProduct(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.maxProduct(NUMS2));
    }
}