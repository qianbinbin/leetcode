package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TwoSumTest {
    private static final TwoSum.Solution1 SOLUTION1 = new TwoSum.Solution1();

    private final int[] NUMS1 = {2, 7, 11, 15};
    private final int TARGET1 = 9;
    private final int[] EXPECTED1 = {0, 1};

    private final int[] NUMS2 = {3, 2, 4};
    private final int TARGET2 = 6;
    private final int[] EXPECTED2 = {1, 2};

    private final int[] NUMS3 = {3, 3};
    private final int TARGET3 = 6;
    private final int[] EXPECTED3 = {0, 1};

    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.twoSum(NUMS1, TARGET1));
        assertArrayEquals(EXPECTED2, SOLUTION1.twoSum(NUMS2, TARGET2));
        assertArrayEquals(EXPECTED3, SOLUTION1.twoSum(NUMS3, TARGET3));
    }
}