package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MergeSortedArrayTest {
    private static final MergeSortedArray.Solution1 SOLUTION1 = new MergeSortedArray.Solution1();

    private int[] getNUMS11() {
        return new int[]{1, 2, 3, 0, 0, 0};
    }

    ;
    private final int M1 = 3;
    private final int[] NUMS12 = {2, 5, 6};
    private final int N1 = 3;
    private final int[] EXPECTED1 = {1, 2, 2, 3, 5, 6};

    private int[] getNUMS21() {
        return new int[]{1};
    }

    private final int M2 = 1;
    private final int[] NUMS22 = {};
    private final int N2 = 0;
    private final int[] EXPECTED2 = {1};

    private int[] getNUMS31() {
        return new int[]{0};
    }

    private final int M3 = 0;
    private final int[] NUMS32 = {1};
    private final int N3 = 1;
    private final int[] EXPECTED3 = {1};

    @Test
    void test1() {
        int[] nums1 = getNUMS11();
        SOLUTION1.merge(nums1, M1, NUMS12, N1);
        assertArrayEquals(EXPECTED1, nums1);

        int[] nums2 = getNUMS21();
        SOLUTION1.merge(nums2, M2, NUMS22, N2);
        assertArrayEquals(EXPECTED2, nums2);

        int[] nums3 = getNUMS31();
        SOLUTION1.merge(nums3, M3, NUMS32, N3);
        assertArrayEquals(EXPECTED3, nums3);
    }
}