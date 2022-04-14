package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BasicCalculatorIITest {
    private static final BasicCalculatorII.Solution1 SOLUTION1 = new BasicCalculatorII.Solution1();

    private final String S1 = "3+2*2";
    private final int EXPECTED1 = 7;

    private final String S2 = " 3/2 ";
    private final int EXPECTED2 = 1;

    private final String S3 = " 3+5 / 2 ";
    private final int EXPECTED3 = 5;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.calculate(S1));
        assertEquals(EXPECTED2, SOLUTION1.calculate(S2));
        assertEquals(EXPECTED3, SOLUTION1.calculate(S3));
    }
}