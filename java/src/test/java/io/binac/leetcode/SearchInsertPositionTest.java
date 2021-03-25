package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchInsertPositionTest {
    private static final SearchInsertPosition.Solution1 SOLUTION1 = new SearchInsertPosition.Solution1();

    private final int[] NUMS1 = {1, 3, 5, 6};
    private final int TARGET1 = 5;
    private final int EXPECTED1 = 2;

    private final int[] NUMS2 = {1, 3, 5, 6};
    private final int TARGET2 = 2;
    private final int EXPECTED2 = 1;

    private final int[] NUMS3 = {1, 3, 5, 6};
    private final int TARGET3 = 7;
    private final int EXPECTED3 = 4;

    private final int[] NUMS4 = {1, 3, 5, 6};
    private final int TARGET4 = 0;
    private final int EXPECTED4 = 0;

    private final int[] NUMS5 = {1};
    private final int TARGET5 = 0;
    private final int EXPECTED5 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.searchInsert(NUMS1, TARGET1));
        assertEquals(EXPECTED2, SOLUTION1.searchInsert(NUMS2, TARGET2));
        assertEquals(EXPECTED3, SOLUTION1.searchInsert(NUMS3, TARGET3));
        assertEquals(EXPECTED4, SOLUTION1.searchInsert(NUMS4, TARGET4));
        assertEquals(EXPECTED5, SOLUTION1.searchInsert(NUMS5, TARGET5));
    }
}