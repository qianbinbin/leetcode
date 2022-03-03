package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestConsecutiveSequenceTest {
    private static final LongestConsecutiveSequence.Solution1 SOLUTION1 = new LongestConsecutiveSequence.Solution1();
    private static final LongestConsecutiveSequence.Solution2 SOLUTION2 = new LongestConsecutiveSequence.Solution2();

    private final int[] NUMS1 = {100, 4, 200, 1, 3, 2};
    private final int EXPECTED1 = 4;

    private final int[] NUMS2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    private final int EXPECTED2 = 9;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.longestConsecutive(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.longestConsecutive(NUMS2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.longestConsecutive(NUMS1));
        assertEquals(EXPECTED2, SOLUTION2.longestConsecutive(NUMS2));
    }
}