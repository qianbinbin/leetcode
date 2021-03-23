package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchInRotatedSortedArrayTest {
    private static final SearchInRotatedSortedArray.Solution1 SOLUTION1 = new SearchInRotatedSortedArray.Solution1();

    private final int[] NUMS1 = {4, 5, 6, 7, 0, 1, 2};
    private final int TARGET1 = 0;
    private final int EXPECTED1 = 4;

    private final int[] NUMS2 = {4, 5, 6, 7, 0, 1, 2};
    private final int TARGET2 = 3;
    private final int EXPECTED2 = -1;

    private final int[] NUMS3 = {1};
    private final int TARGET3 = 0;
    private final int EXPECTED3 = -1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.search(NUMS1, TARGET1));
        assertEquals(EXPECTED2, SOLUTION1.search(NUMS2, TARGET2));
        assertEquals(EXPECTED3, SOLUTION1.search(NUMS3, TARGET3));
    }
}