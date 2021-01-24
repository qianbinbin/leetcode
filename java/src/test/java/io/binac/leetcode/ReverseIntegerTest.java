package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseIntegerTest {
    private static final ReverseInteger.Solution1 SOLUTION1 = new ReverseInteger.Solution1();

    private final int X1 = 123;
    private final int EXPECTED1 = 321;

    private final int X2 = -123;
    private final int EXPECTED2 = -321;

    private final int X3 = 120;
    private final int EXPECTED3 = 21;

    private final int X4 = 0;
    private final int EXPECTED4 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.reverse(X1));
        assertEquals(EXPECTED2, SOLUTION1.reverse(X2));
        assertEquals(EXPECTED3, SOLUTION1.reverse(X3));
        assertEquals(EXPECTED4, SOLUTION1.reverse(X4));
    }
}