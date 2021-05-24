package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PowXNTest {
    private static final PowXN.Solution1 SOLUTION1 = new PowXN.Solution1();

    private static final double DELTA = 0.000001;

    private final double X1 = 2.00000;
    private final int N1 = 10;
    private final double EXPECTED1 = 1024.00000;

    private final double X2 = 2.10000;
    private final int N2 = 3;
    private final double EXPECTED2 = 9.26100;

    private final double X3 = 2.00000;
    private final int N3 = -2;
    private final double EXPECTED3 = 0.25000;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.myPow(X1, N1), DELTA);
        assertEquals(EXPECTED2, SOLUTION1.myPow(X2, N2), DELTA);
        assertEquals(EXPECTED3, SOLUTION1.myPow(X3, N3), DELTA);
    }
}