package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestIncreasingSubsequenceTest {
    private static final LongestIncreasingSubsequence.Solution1 SOLUTION1 = new LongestIncreasingSubsequence.Solution1();
    private static final LongestIncreasingSubsequence.Solution2 SOLUTION2 = new LongestIncreasingSubsequence.Solution2();

    private final int[] NUMS1 = {10, 9, 2, 5, 3, 7, 101, 18};
    private final int EXPECTED1 = 4;

    private final int[] NUMS2 = {0, 1, 0, 3, 2, 3};
    private final int EXPECTED2 = 4;

    private final int[] NUMS3 = {7, 7, 7, 7, 7, 7, 7};
    private final int EXPECTED3 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.lengthOfLIS(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.lengthOfLIS(NUMS2));
        assertEquals(EXPECTED3, SOLUTION1.lengthOfLIS(NUMS3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.lengthOfLIS(NUMS1));
        assertEquals(EXPECTED2, SOLUTION2.lengthOfLIS(NUMS2));
        assertEquals(EXPECTED3, SOLUTION2.lengthOfLIS(NUMS3));
    }
}