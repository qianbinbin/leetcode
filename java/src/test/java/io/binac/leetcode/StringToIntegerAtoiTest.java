package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StringToIntegerAtoiTest {
    private static final StringToIntegerAtoi.Solution1 SOLUTION1 = new StringToIntegerAtoi.Solution1();

    private final String S1 = "42";
    private final int EXPECTED1 = 42;

    private final String S2 = "-42";
    private final int EXPECTED2 = -42;

    private final String S3 = "4193 with words";
    private final int EXPECTED3 = 4193;

    private final String S4 = "words and 987";
    private final int EXPECTED4 = 0;

    private final String S5 = "-91283472332";
    private final int EXPECTED5 = Integer.MIN_VALUE;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.myAtoi(S1));
        assertEquals(EXPECTED2, SOLUTION1.myAtoi(S2));
        assertEquals(EXPECTED3, SOLUTION1.myAtoi(S3));
        assertEquals(EXPECTED4, SOLUTION1.myAtoi(S4));
        assertEquals(EXPECTED5, SOLUTION1.myAtoi(S5));
    }
}