package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DivideTwoIntegersTest {
    private static final DivideTwoIntegers.Solution1 SOLUTION1 = new DivideTwoIntegers.Solution1();

    private final int DIVIDEND1 = 10, DIVISOR1 = 3, EXPECTED1 = 3;

    private final int DIVIDEND2 = 7, DIVISOR2 = -3, EXPECTED2 = -2;

    private final int DIVIDEND3 = 0, DIVISOR3 = 1, EXPECTED3 = 0;

    private final int DIVIDEND4 = 1, DIVISOR4 = 1, EXPECTED4 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.divide(DIVIDEND1, DIVISOR1));
        assertEquals(EXPECTED2, SOLUTION1.divide(DIVIDEND2, DIVISOR2));
        assertEquals(EXPECTED3, SOLUTION1.divide(DIVIDEND3, DIVISOR3));
        assertEquals(EXPECTED4, SOLUTION1.divide(DIVIDEND4, DIVISOR4));
    }
}