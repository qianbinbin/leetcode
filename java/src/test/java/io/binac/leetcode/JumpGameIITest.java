package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class JumpGameIITest {
    private static final JumpGameII.Solution1 SOLUTION1 = new JumpGameII.Solution1();

    private final int[] NUMS1 = {2, 3, 1, 1, 4};
    private final int EXPECTED1 = 2;

    private final int[] NUMS2 = {2, 3, 0, 1, 4};
    private final int EXPECTED2 = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.jump(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.jump(NUMS2));
    }
}