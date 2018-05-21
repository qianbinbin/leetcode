package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MedianOfTwoSortedArraysTest {
    private final MedianOfTwoSortedArrays.Solution1 solution1 = new MedianOfTwoSortedArrays.Solution1();

    @Test
    void test1() {
        int nums1[] = {1, 3};
        int nums2[] = {2};
        assertEquals(2, solution1.findMedianSortedArrays(nums1, nums2));
        int nums3[] = {1, 2};
        int nums4[] = {3, 4};
        assertEquals(2.5, solution1.findMedianSortedArrays(nums3, nums4));
    }

    @Test
    void test1Empty() {
        int nums1[] = {};
        int nums2[] = {1};
        assertEquals(1, solution1.findMedianSortedArrays(nums1, nums2));
    }
}