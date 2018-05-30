package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class RemoveElementTest {
    private final RemoveElement.Solution1 solution1 = new RemoveElement.Solution1();

    @Test
    void test1() {
        int nums1[] = {3, 2, 2, 3};
        int size1 = solution1.removeElement(nums1, 3);
        int result1[] = Arrays.copyOf(nums1, size1);
        int expected1[] = {2, 2};
        assertTrue(Arrays.equals(expected1, result1));

        int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
        int size2 = solution1.removeElement(nums2, 2);
        int result2[] = Arrays.copyOf(nums2, size2);
        int expected2[] = {0, 1, 3, 0, 4};
        assertTrue(Arrays.equals(expected2, result2));
    }
}