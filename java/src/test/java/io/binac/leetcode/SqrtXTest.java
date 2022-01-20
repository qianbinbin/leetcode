package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SqrtXTest {
    private static final SqrtX.Solution1 SOLUTION1 = new SqrtX.Solution1();
    private static final SqrtX.Solution2 SOLUTION2 = new SqrtX.Solution2();
    private static final SqrtX.Solution3 SOLUTION3 = new SqrtX.Solution3();

    private final int X1 = 4, EXPECTED1 = 2;

    private final int X2 = 8, EXPECTED2 = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.mySqrt(X1));
        assertEquals(EXPECTED2, SOLUTION1.mySqrt(X2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.mySqrt(X1));
        assertEquals(EXPECTED2, SOLUTION2.mySqrt(X2));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.mySqrt(X1));
        assertEquals(EXPECTED2, SOLUTION3.mySqrt(X2));
    }
}