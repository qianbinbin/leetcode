package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class JumpGameTest {
    private final JumpGame.Solution1 solution1 = new JumpGame.Solution1();

    private final JumpGame.Solution2 solution2 = new JumpGame.Solution2();

    @Test
    void test1() {
        int nums1[] = {2, 3, 1, 1, 4};
        assertTrue(solution1.canJump(nums1));
        int nums2[] = {3, 2, 1, 0, 4};
        assertFalse(solution1.canJump(nums2));
    }

    @Test
    void test2() {
        int nums1[] = {2, 3, 1, 1, 4};
        assertTrue(solution2.canJump(nums1));
        int nums2[] = {3, 2, 1, 0, 4};
        assertFalse(solution2.canJump(nums2));
    }
}