package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MedianOfTwoSortedArraysTest {
    private static final MedianOfTwoSortedArrays.Solution1 SOLUTION1 = new MedianOfTwoSortedArrays.Solution1();

    private final int[] NUMS11 = {1, 3};
    private final int[] NUMS12 = {2};
    private final double EXPECTED1 = 2;

    private final int[] NUMS21 = {1, 2};
    private final int[] NUMS22 = {3, 4};
    private final double EXPECTED2 = 2.5;

    private final int[] NUMS31 = {0, 0};
    private final int[] NUMS32 = {0, 0};
    private final double EXPECTED3 = 0;

    private final int[] NUMS41 = {};
    private final int[] NUMS42 = {1};
    private final double EXPECTED4 = 1;

    private final int[] NUMS51 = {2};
    private final int[] NUMS52 = {};
    private final double EXPECTED5 = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.findMedianSortedArrays(NUMS11, NUMS12));
        assertEquals(EXPECTED2, SOLUTION1.findMedianSortedArrays(NUMS21, NUMS22));
        assertEquals(EXPECTED3, SOLUTION1.findMedianSortedArrays(NUMS31, NUMS32));
        assertEquals(EXPECTED4, SOLUTION1.findMedianSortedArrays(NUMS41, NUMS42));
        assertEquals(EXPECTED5, SOLUTION1.findMedianSortedArrays(NUMS51, NUMS52));
    }
}