package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FindFirstAndLastPositionOfElementInSortedArrayTest {
    private static final FindFirstAndLastPositionOfElementInSortedArray.Solution1 SOLUTION1 = new FindFirstAndLastPositionOfElementInSortedArray.Solution1();

    private final int[] NUMS1 = {5, 7, 7, 8, 8, 10};
    private final int TARGET1 = 8;
    private final int[] EXPECTED1 = {3, 4};

    private final int[] NUMS2 = {5, 7, 7, 8, 8, 10};
    private final int TARGET2 = 6;
    private final int[] EXPECTED2 = {-1, -1};

    private final int[] NUMS3 = {};
    private final int TARGET3 = 0;
    private final int[] EXPECTED3 = {-1, -1};

    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.searchRange(NUMS1, TARGET1));
        assertArrayEquals(EXPECTED2, SOLUTION1.searchRange(NUMS2, TARGET2));
        assertArrayEquals(EXPECTED3, SOLUTION1.searchRange(NUMS3, TARGET3));
    }
}