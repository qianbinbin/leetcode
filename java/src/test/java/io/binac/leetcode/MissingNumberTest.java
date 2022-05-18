package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MissingNumberTest {
    private static final MissingNumber.Solution1 SOLUTION1 = new MissingNumber.Solution1();
    private static final MissingNumber.Solution2 SOLUTION2 = new MissingNumber.Solution2();
    private static final MissingNumber.Solution3 SOLUTION3 = new MissingNumber.Solution3();

    private final int[] NUMS1 = {3, 0, 1};
    private final int EXPECTED1 = 2;

    private final int[] NUMS2 = {0, 1};
    private final int EXPECTED2 = 2;

    private final int[] NUMS3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    private final int EXPECTED3 = 8;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.missingNumber(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.missingNumber(NUMS2));
        assertEquals(EXPECTED3, SOLUTION1.missingNumber(NUMS3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.missingNumber(NUMS1));
        assertEquals(EXPECTED2, SOLUTION2.missingNumber(NUMS2));
        assertEquals(EXPECTED3, SOLUTION2.missingNumber(NUMS3));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.missingNumber(NUMS1));
        assertEquals(EXPECTED2, SOLUTION3.missingNumber(NUMS2));
        assertEquals(EXPECTED3, SOLUTION3.missingNumber(NUMS3));
    }
}