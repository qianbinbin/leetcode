package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FirstMissingPositiveTest {
    private final FirstMissingPositive.Solution1 solution1 = new FirstMissingPositive.Solution1();

    @Test
    void test1() {
        int nums1[] = {1, 2, 0};
        assertEquals(3, solution1.firstMissingPositive(nums1));
        int nums2[] = {3, 4, -1, 1};
        assertEquals(2, solution1.firstMissingPositive(nums2));
        int nums3[] = {7, 8, 9, 11, 12};
        assertEquals(1, solution1.firstMissingPositive(nums3));
    }
}