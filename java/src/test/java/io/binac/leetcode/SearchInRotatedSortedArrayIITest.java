package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SearchInRotatedSortedArrayIITest {
    private final SearchInRotatedSortedArrayII.Solution1 solution1 = new SearchInRotatedSortedArrayII.Solution1();

    @Test
    void test1() {
        int nums1[] = {2, 5, 6, 0, 0, 1, 2};
        assertTrue(solution1.search(nums1, 0));
        int nums2[] = {2, 5, 6, 0, 0, 1, 2};
        assertFalse(solution1.search(nums2, 3));
        int nums3[] = {1,1,3,1};
        assertTrue(solution1.search(nums3, 3));
    }
}