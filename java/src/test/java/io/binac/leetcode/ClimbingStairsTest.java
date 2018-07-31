package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ClimbingStairsTest {
    private final ClimbingStairs.Solution1 solution1 = new ClimbingStairs.Solution1();

    @Test
    void test1() {
        assertEquals(2, solution1.climbStairs(2));
        assertEquals(3, solution1.climbStairs(3));
    }
}