package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class KthLargestElementInAnArrayTest {
    private static final KthLargestElementInAnArray.Solution1 SOLUTION1 = new KthLargestElementInAnArray.Solution1();
    private static final KthLargestElementInAnArray.Solution2 SOLUTION2 = new KthLargestElementInAnArray.Solution2();

    private final int[] NUMS1 = {3, 2, 1, 5, 6, 4};
    private final int K1 = 2;
    private final int EXPECTED1 = 5;

    private final int[] NUMS2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    private final int K2 = 4;
    private final int EXPECTED2 = 4;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.findKthLargest(NUMS1, K1));
        assertEquals(EXPECTED2, SOLUTION1.findKthLargest(NUMS2, K2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.findKthLargest(NUMS1, K1));
        assertEquals(EXPECTED2, SOLUTION2.findKthLargest(NUMS2, K2));
    }
}