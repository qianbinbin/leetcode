package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PowXNTest {
    private static final double DELTA = 0.000001;

    private final PowXN.Solution1 solution1 = new PowXN.Solution1();

    @Test
    void test1() {
        assertEquals(1024.00000, solution1.myPow(2.00000, 10), DELTA);
        assertEquals(9.26100, solution1.myPow(2.10000, 3), DELTA);
        assertEquals(0.25000, solution1.myPow(2.00000, -2), DELTA);
    }
}