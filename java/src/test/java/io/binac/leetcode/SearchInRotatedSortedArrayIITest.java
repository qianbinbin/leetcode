package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchInRotatedSortedArrayIITest {
    private static final SearchInRotatedSortedArrayII.Solution1 SOLUTION1 = new SearchInRotatedSortedArrayII.Solution1();

    private final int[] NUMS1 = {2, 5, 6, 0, 0, 1, 2};
    private final int TARGET1 = 0;
    private final boolean EXPECTED1 = true;

    private final int[] NUMS2 = NUMS1;
    private final int TARGET2 = 3;
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.search(NUMS1, TARGET1));
        assertEquals(EXPECTED2, SOLUTION1.search(NUMS2, TARGET2));
    }
}