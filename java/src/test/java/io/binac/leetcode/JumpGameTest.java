package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class JumpGameTest {
    private static final JumpGame.Solution1 SOLUTION1 = new JumpGame.Solution1();
    private static final JumpGame.Solution2 SOLUTION2 = new JumpGame.Solution2();

    private final int[] NUMS1 = {2, 3, 1, 1, 4};
    private final boolean EXPECTED1 = true;
    private final int[] NUMS2 = {3, 2, 1, 0, 4};
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.canJump(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.canJump(NUMS2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.canJump(NUMS1));
        assertEquals(EXPECTED2, SOLUTION2.canJump(NUMS2));
    }
}