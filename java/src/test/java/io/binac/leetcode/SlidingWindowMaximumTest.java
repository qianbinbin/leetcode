package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SlidingWindowMaximumTest {
    private static final SlidingWindowMaximum.Solution1 SOLUTION1 = new SlidingWindowMaximum.Solution1();
    private static final SlidingWindowMaximum.Solution2 SOLUTION2 = new SlidingWindowMaximum.Solution2();
    private static final SlidingWindowMaximum.Solution3 SOLUTION3 = new SlidingWindowMaximum.Solution3();

    private final int[] NUMS1 = {1, 3, -1, -3, 5, 3, 6, 7};
    private final int K1 = 3;
    private final int[] EXPECTED1 = {3, 3, 5, 5, 6, 7};

    private final int[] NUMS2 = {1};
    private final int K2 = 1;
    private final int[] EXPECTED2 = {1};

    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.maxSlidingWindow(NUMS1, K1));
        assertArrayEquals(EXPECTED2, SOLUTION1.maxSlidingWindow(NUMS2, K2));
    }

    @Test
    void test2() {
        assertArrayEquals(EXPECTED1, SOLUTION2.maxSlidingWindow(NUMS1, K1));
        assertArrayEquals(EXPECTED2, SOLUTION2.maxSlidingWindow(NUMS2, K2));
    }

    @Test
    void test3() {
        assertArrayEquals(EXPECTED1, SOLUTION3.maxSlidingWindow(NUMS1, K1));
        assertArrayEquals(EXPECTED2, SOLUTION3.maxSlidingWindow(NUMS2, K2));
    }
}