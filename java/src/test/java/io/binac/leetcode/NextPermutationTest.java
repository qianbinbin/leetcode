package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NextPermutationTest {
    private static final NextPermutation.Solution1 SOLUTION1 = new NextPermutation.Solution1();

    private final int[] NUMS1 = {1, 2, 3};
    private final int[] EXPECTED1 = {1, 3, 2};

    private final int[] NUMS2 = {3, 2, 1};
    private final int[] EXPECTED2 = {1, 2, 3};

    private final int[] NUMS3 = {1, 1, 5};
    private final int[] EXPECTED3 = {1, 5, 1};

    private final int[] NUMS4 = {1};
    private final int[] EXPECTED4 = {1};

    @Test
    void test1() {
        SOLUTION1.nextPermutation(NUMS1);
        assertArrayEquals(EXPECTED1, NUMS1);

        SOLUTION1.nextPermutation(NUMS2);
        assertArrayEquals(EXPECTED2, NUMS2);

        SOLUTION1.nextPermutation(NUMS3);
        assertArrayEquals(EXPECTED3, NUMS3);

        SOLUTION1.nextPermutation(NUMS4);
        assertArrayEquals(EXPECTED4, NUMS4);
    }
}