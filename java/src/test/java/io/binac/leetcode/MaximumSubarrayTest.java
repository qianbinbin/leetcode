package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumSubarrayTest {
    private final MaximumSubarray.Solution1 solution1 = new MaximumSubarray.Solution1();

    private final MaximumSubarray.Solution2 solution2 = new MaximumSubarray.Solution2();

    @Test
    void test1() {
        int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        assertEquals(6, solution1.maxSubArray(nums));
    }

    @Test
    void test2() {
        int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        assertEquals(6, solution2.maxSubArray(nums));
    }
}