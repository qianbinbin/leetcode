package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FirstMissingPositiveTest {
    private static final FirstMissingPositive.Solution1 SOLUTION1 = new FirstMissingPositive.Solution1();

    private final int[] NUMS1 = {1, 2, 0};
    private final int EXPECTED1 = 3;

    private final int[] NUMS2 = {3, 4, -1, 1};
    private final int EXPECTED2 = 2;

    private final int[] NUMS3 = {7, 8, 9, 11, 12};
    private final int EXPECTED3 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.firstMissingPositive(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.firstMissingPositive(NUMS2));
        assertEquals(EXPECTED3, SOLUTION1.firstMissingPositive(NUMS3));
    }
}