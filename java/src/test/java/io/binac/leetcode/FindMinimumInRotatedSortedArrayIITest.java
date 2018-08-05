package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FindMinimumInRotatedSortedArrayIITest {

    private final FindMinimumInRotatedSortedArrayII.Solution1 solution1 = new FindMinimumInRotatedSortedArrayII.Solution1();

    private final int nums1[] = {1, 3, 5};

    private final int expected1 = 1;

    private final int nums2[] = {2, 2, 2, 0, 1};

    private final int expected2 = 0;

    @Test
    void test1() {
        assertEquals(expected1, solution1.findMin(nums1));
        assertEquals(expected2, solution1.findMin(nums2));
    }
}