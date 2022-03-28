package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RotateArrayTest {
    private static final RotateArray.Solution1 SOLUTION1 = new RotateArray.Solution1();

    private int[] getNUMS1() {
        return new int[]{1, 2, 3, 4, 5, 6, 7};
    }

    private final int K1 = 3;
    private final int[] EXPECTED1 = {5, 6, 7, 1, 2, 3, 4};

    private int[] getNUMS2() {
        return new int[]{-1, -100, 3, 99};
    }

    private final int K2 = 2;
    private final int[] EXPECTED2 = {3, 99, -1, -100};

    @Test
    void test1() {
        int[] nums1 = getNUMS1();
        SOLUTION1.rotate(nums1, K1);
        assertArrayEquals(EXPECTED1, nums1);

        int[] nums2 = getNUMS2();
        SOLUTION1.rotate(nums2, K2);
        assertArrayEquals(EXPECTED2, nums2);
    }
}