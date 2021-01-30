package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RomanToIntegerTest {
    private static final RomanToInteger.Solution1 SOLUTION1 = new RomanToInteger.Solution1();

    private final String S1 = "III";
    private final int EXPECTED1 = 3;

    private final String S2 = "IV";
    private final int EXPECTED2 = 4;

    private final String S3 = "IX";
    private final int EXPECTED3 = 9;

    private final String S4 = "LVIII";
    private final int EXPECTED4 = 58;

    private final String S5 = "MCMXCIV";
    private final int EXPECTED5 = 1994;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.romanToInt(S1));
        assertEquals(EXPECTED2, SOLUTION1.romanToInt(S2));
        assertEquals(EXPECTED3, SOLUTION1.romanToInt(S3));
        assertEquals(EXPECTED4, SOLUTION1.romanToInt(S4));
        assertEquals(EXPECTED5, SOLUTION1.romanToInt(S5));
    }
}