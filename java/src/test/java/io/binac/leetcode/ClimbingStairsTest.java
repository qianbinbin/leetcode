package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ClimbingStairsTest {
    private static final ClimbingStairs.Solution1 SOLUTION1 = new ClimbingStairs.Solution1();

    private final int N1 = 2, EXPECTED1 = 2;

    private final int N2 = 3, EXPECTED2 = 3;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.climbStairs(N1));
        assertEquals(EXPECTED2, SOLUTION1.climbStairs(N2));
    }
}