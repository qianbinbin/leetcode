package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class RemoveDuplicatesFromSortedArrayTest {
    private final RemoveDuplicatesFromSortedArray.Solution1 solution1 = new RemoveDuplicatesFromSortedArray.Solution1();

    @Test
    void test1() {
        int nums1[] = {1, 1, 2};
        int size1 = solution1.removeDuplicates(nums1);
        int result1[] = Arrays.copyOf(nums1, size1);
        int expected1[] = {1, 2};
        assertTrue(Arrays.equals(expected1, result1));

        int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int size2 = solution1.removeDuplicates(nums2);
        int result2[] = Arrays.copyOf(nums2, size2);
        int expected2[] = {0, 1, 2, 3, 4};
        assertTrue(Arrays.equals(expected2, result2));
    }
}