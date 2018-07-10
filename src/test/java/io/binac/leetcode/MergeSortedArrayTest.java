package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MergeSortedArrayTest {
    private final MergeSortedArray.Solution1 solution1 = new MergeSortedArray.Solution1();

    @Test
    void test1() {
        int nums1[] = {1, 2, 3, 0, 0, 0};
        int nums2[] = {2, 5, 6};
        int expected[] = {1, 2, 2, 3, 5, 6};
        solution1.merge(nums1, 3, nums2, 3);
        assertArrayEquals(expected, nums1);
    }
}