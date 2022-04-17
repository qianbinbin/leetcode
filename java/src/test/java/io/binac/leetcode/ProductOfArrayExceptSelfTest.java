package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ProductOfArrayExceptSelfTest {
    private static final ProductOfArrayExceptSelf.Solution1 SOLUTION1 = new ProductOfArrayExceptSelf.Solution1();

    private final int[] NUMS1 = {1, 2, 3, 4};
    private final int[] EXPECTED1 = {24, 12, 8, 6};

    private final int[] NUMS2 = {-1, 1, 0, -3, 3};
    private final int[] EXPECTED2 = {0, 0, 9, 0, 0};

    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.productExceptSelf(NUMS1));
        assertArrayEquals(EXPECTED2, SOLUTION1.productExceptSelf(NUMS2));
    }
}