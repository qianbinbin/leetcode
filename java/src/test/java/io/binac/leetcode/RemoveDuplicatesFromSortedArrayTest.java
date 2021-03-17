package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class RemoveDuplicatesFromSortedArrayTest {
    private static final RemoveDuplicatesFromSortedArray.Solution1 SOLUTION1 = new RemoveDuplicatesFromSortedArray.Solution1();

    private final int[] NUMS1 = {1, 1, 2};
    private final int[] EXPECTED1 = {1, 2};

    private final int[] NUMS2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    private final int[] EXPECTED2 = {0, 1, 2, 3, 4};

    @Test
    void test1() {
        int size1 = SOLUTION1.removeDuplicates(NUMS1);
        assertEquals(EXPECTED1.length, size1);
        assertArrayEquals(EXPECTED1, Arrays.copyOf(NUMS1, size1));

        int size2 = SOLUTION1.removeDuplicates(NUMS2);
        assertEquals(EXPECTED2.length, size2);
        assertArrayEquals(EXPECTED2, Arrays.copyOf(NUMS2, size2));
    }
}