package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NextPermutationTest {
    private final NextPermutation.Solution1 solution1 = new NextPermutation.Solution1();

    @Test
    void test1() {
        int nums1[] = {1, 2, 3};
        solution1.nextPermutation(nums1);
        int expected1[] = {1, 3, 2};
        assertArrayEquals(expected1, nums1);

        int nums2[] = {3, 2, 1};
        solution1.nextPermutation(nums2);
        int expected2[] = {1, 2, 3};
        assertArrayEquals(expected2, nums2);

        int nums3[] = {1, 1, 5};
        solution1.nextPermutation(nums3);
        int expected3[] = {1, 5, 1};
        assertArrayEquals(expected3, nums3);
    }
}