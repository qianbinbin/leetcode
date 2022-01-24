package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class RemoveDuplicatesFromSortedArrayIITest {
    private static final RemoveDuplicatesFromSortedArrayII.Solution1 SOLUTION1 = new RemoveDuplicatesFromSortedArrayII.Solution1();

    private int[] getNUMS1() {
        return new int[]{1, 1, 1, 2, 2, 3};
    }

    private final int[] EXPECTED1 = {1, 1, 2, 2, 3};

    private int[] getNUMS2() {
        return new int[]{0, 0, 1, 1, 1, 1, 2, 3, 3};
    }

    private final int[] EXPECTED2 = {0, 0, 1, 1, 2, 3, 3};

    @Test
    void test1() {
        int[] nums1 = getNUMS1();
        int size1 = SOLUTION1.removeDuplicates(nums1);
        int[] actual1 = Arrays.copyOf(nums1, size1);
        assertArrayEquals(EXPECTED1, actual1);

        int[] nums2 = getNUMS2();
        int size2 = SOLUTION1.removeDuplicates(nums2);
        int[] actual2 = Arrays.copyOf(nums2, size2);
        assertArrayEquals(EXPECTED2, actual2);
    }
}