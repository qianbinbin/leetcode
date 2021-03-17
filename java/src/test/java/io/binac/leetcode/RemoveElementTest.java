package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class RemoveElementTest {
    private static final RemoveElement.Solution1 SOLUTION1 = new RemoveElement.Solution1();

    private final int[] NUMS1 = {3, 2, 2, 3};
    private final int VAL1 = 3;
    private final int[] EXPECTED1 = {2, 2};

    private final int[] NUMS2 = {0, 1, 2, 2, 3, 0, 4, 2};
    private final int VAL2 = 2;
    private final int[] EXPECTED2 = {0, 1, 3, 0, 4};

    @Test
    void test1() {
        int size1 = SOLUTION1.removeElement(NUMS1, VAL1);
        assertEquals(EXPECTED1.length, size1);
        assertArrayEquals(EXPECTED1, Arrays.copyOf(NUMS1, size1));

        int size2 = SOLUTION1.removeElement(NUMS2, VAL2);
        assertEquals(EXPECTED2.length, size2);
        assertArrayEquals(EXPECTED2, Arrays.copyOf(NUMS2, size2));
    }
}