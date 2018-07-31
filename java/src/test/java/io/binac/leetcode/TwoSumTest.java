package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TwoSumTest {
    private final TwoSum.Solution1 solution1 = new TwoSum.Solution1();

    @Test
    void test1() {
        int nums[] = {2, 7, 11, 15};
        int result[] = solution1.twoSum(nums, 9);
        int expected[] = {0, 1};
        assertArrayEquals(expected, result);
    }
}