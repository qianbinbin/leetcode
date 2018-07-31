package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SingleNumberTest {
    private final SingleNumber.Solution1 solution1 = new SingleNumber.Solution1();

    @Test
    void test1() {
        int nums1[] = {2, 2, 1};
        assertEquals(1, solution1.singleNumber(nums1));

        int nums2[] = {4, 1, 2, 1, 2};
        assertEquals(4, solution1.singleNumber(nums2));
    }
}