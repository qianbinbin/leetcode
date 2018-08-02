package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumProductSubarrayTest {

    private final MaximumProductSubarray.Solution1 solution1 = new MaximumProductSubarray.Solution1();

    private final int nums1[] = {2, 3, -2, 4};

    private final int expected1 = 6;

    private final int nums2[] = {-2, 0, -1};

    private final int expected2 = 0;

    @Test
    void test1() {
        assertEquals(expected1, solution1.maxProduct(nums1));
        assertEquals(expected2, solution1.maxProduct(nums2));
    }
}