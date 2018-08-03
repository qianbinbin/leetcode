package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FindMinimumInRotatedSortedArrayTest {

    private final FindMinimumInRotatedSortedArray.Solution1 solution1 = new FindMinimumInRotatedSortedArray.Solution1();

    private final int nums1[] = {3, 4, 5, 1, 2};

    private final int expected1 = 1;

    private final int nums2[] = {4, 5, 6, 7, 0, 1, 2};

    private final int expected2 = 0;

    @Test
    void test1() {
        assertEquals(expected1, solution1.findMin(nums1));
        assertEquals(expected2, solution1.findMin(nums2));
    }
}