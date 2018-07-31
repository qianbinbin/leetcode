package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class JumpGameIITest {
    private final JumpGameII.Solution1 solution1 = new JumpGameII.Solution1();

    @Test
    void test1() {
        int nums[] = {2, 3, 1, 1, 4};
        assertEquals(2, solution1.jump(nums));
    }
}