package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MoveZeroesTest {
    private static final MoveZeroes.Solution1 SOLUTION1 = new MoveZeroes.Solution1();

    private int[] getNUMS1() {
        return new int[]{0, 1, 0, 3, 12};
    }

    private final int[] EXPECTED1 = {1, 3, 12, 0, 0};

    private int[] getNUMS2() {
        return new int[]{0};
    }

    private final int[] EXPECTED2 = {0};

    @Test
    void test1() {
        int[] nums1 = getNUMS1();
        SOLUTION1.moveZeroes(nums1);
        assertArrayEquals(EXPECTED1, nums1);

        int[] nums2 = getNUMS2();
        SOLUTION1.moveZeroes(nums2);
        assertArrayEquals(EXPECTED2, nums2);
    }
}