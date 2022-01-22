package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SortColorsTest {
    private static final SortColors.Solution1 SOLUTION1 = new SortColors.Solution1();
    private static final SortColors.Solution2 SOLUTION2 = new SortColors.Solution2();

    private int[] getNUMS1() {
        return new int[]{2, 0, 2, 1, 1, 0};
    }

    private final int[] EXPECTED1 = {0, 0, 1, 1, 2, 2};

    private int[] getNUMS2() {
        return new int[]{2, 0, 1};
    }

    private final int[] EXPECTED2 = {0, 1, 2};

    @Test
    void test1() {
        int[] nums1 = getNUMS1();
        SOLUTION1.sortColors(nums1);
        assertArrayEquals(EXPECTED1, nums1);

        int[] nums2 = getNUMS2();
        SOLUTION1.sortColors(nums2);
        assertArrayEquals(EXPECTED2, nums2);
    }

    @Test
    void test2() {
        int[] nums1 = getNUMS1();
        SOLUTION2.sortColors(nums1);
        assertArrayEquals(EXPECTED1, nums1);

        int[] nums2 = getNUMS2();
        SOLUTION2.sortColors(nums2);
        assertArrayEquals(EXPECTED2, nums2);
    }
}