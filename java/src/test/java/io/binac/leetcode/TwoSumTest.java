package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TwoSumTest {
    private final TwoSum.Solution1 solution1 = new TwoSum.Solution1();

    private final int[] nums = {2, 7, 11, 15};
    private final int[] expected = {0, 1};

    @Test
    void test1() {
        assertArrayEquals(expected, solution1.twoSum(nums, 9));
    }
}