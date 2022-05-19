package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PerfectSquaresTest {
    private static final PerfectSquares.Solution1 SOLUTION1 = new PerfectSquares.Solution1();
    private static final PerfectSquares.Solution2 SOLUTION2 = new PerfectSquares.Solution2();
    private static final PerfectSquares.Solution3 SOLUTION3 = new PerfectSquares.Solution3();

    private final int N1 = 12;
    private final int EXPECTED1 = 3;

    private final int N2 = 13;
    private final int EXPECTED2 = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.numSquares(N1));
        assertEquals(EXPECTED2, SOLUTION1.numSquares(N2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.numSquares(N1));
        assertEquals(EXPECTED2, SOLUTION2.numSquares(N2));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.numSquares(N1));
        assertEquals(EXPECTED2, SOLUTION3.numSquares(N2));
    }
}