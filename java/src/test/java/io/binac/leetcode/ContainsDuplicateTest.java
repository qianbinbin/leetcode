package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ContainsDuplicateTest {
    private static final ContainsDuplicate.Solution1 SOLUTION1 = new ContainsDuplicate.Solution1();

    private final int[] NUMS1 = {1, 2, 3, 1};
    private final boolean EXPECTED1 = true;

    private final int[] NUMS2 = {1, 2, 3, 4};
    private final boolean EXPECTED2 = false;

    private final int[] NUMS3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    private final boolean EXPECTED3 = true;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.containsDuplicate(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.containsDuplicate(NUMS2));
        assertEquals(EXPECTED3, SOLUTION1.containsDuplicate(NUMS3));
    }
}