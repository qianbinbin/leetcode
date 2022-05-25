package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FindTheDuplicateNumberTest {
    private static final FindTheDuplicateNumber.Solution1 SOLUTION1 = new FindTheDuplicateNumber.Solution1();
    private static final FindTheDuplicateNumber.Solution2 SOLUTION2 = new FindTheDuplicateNumber.Solution2();
    private static final FindTheDuplicateNumber.Solution3 SOLUTION3 = new FindTheDuplicateNumber.Solution3();

    private final int[] NUMS1 = {1, 3, 4, 2, 2};
    private final int EXPECTED1 = 2;

    private final int[] NUMS2 = {3, 1, 3, 4, 2};
    private final int EXPECTED2 = 3;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.findDuplicate(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.findDuplicate(NUMS2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.findDuplicate(NUMS1));
        assertEquals(EXPECTED2, SOLUTION2.findDuplicate(NUMS2));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.findDuplicate(NUMS1));
        assertEquals(EXPECTED2, SOLUTION3.findDuplicate(NUMS2));
    }
}