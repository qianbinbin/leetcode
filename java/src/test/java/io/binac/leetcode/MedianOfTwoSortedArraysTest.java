package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MedianOfTwoSortedArraysTest {
    private final MedianOfTwoSortedArrays.Solution1 solution1 = new MedianOfTwoSortedArrays.Solution1();

    private final int[] nums11 = {1, 3};
    private final int[] nums12 = {2};
    private final double EXPECTED1 = 2;
    private final int[] nums21 = {1, 2};
    private final int[] nums22 = {3, 4};
    private final double EXPECTED2 = 2.5;
    private final int[] nums31 = {};
    private final int[] nums32 = {1};
    private final double EXPECTED3 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, solution1.findMedianSortedArrays(nums11, nums12));
        assertEquals(EXPECTED2, solution1.findMedianSortedArrays(nums21, nums22));
    }

    @Test
    void test1Empty() {
        assertEquals(EXPECTED3, solution1.findMedianSortedArrays(nums31, nums32));
    }
}