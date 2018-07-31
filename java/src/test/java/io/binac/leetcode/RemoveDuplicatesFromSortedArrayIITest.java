package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class RemoveDuplicatesFromSortedArrayIITest {
    private final RemoveDuplicatesFromSortedArrayII.Solution1 solution1 = new RemoveDuplicatesFromSortedArrayII.Solution1();

    @Test
    void test1() {
        int nums1[] = {1, 1, 1, 2, 2, 3};
        int size1 = solution1.removeDuplicates(nums1);
        int actual1[] = Arrays.copyOf(nums1, size1);
        int expected1[] = {1, 1, 2, 2, 3};
        assertArrayEquals(expected1, actual1);

        int nums2[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        int size2 = solution1.removeDuplicates(nums2);
        int actual2[] = Arrays.copyOf(nums2, size2);
        int expected2[] = {0, 0, 1, 1, 2, 3, 3};
        assertArrayEquals(expected2, actual2);
    }
}