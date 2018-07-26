package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SingleNumberIITest {
    private final SingleNumberII.Solution1 solution1 = new SingleNumberII.Solution1();

    @Test
    void test1() {
        int nums1[] = {2, 2, 3, 2};
        assertEquals(3, solution1.singleNumber(nums1));

        int nums2[] = {0, 1, 0, 1, 0, 1, 99};
        assertEquals(99, solution1.singleNumber(nums2));
    }
}