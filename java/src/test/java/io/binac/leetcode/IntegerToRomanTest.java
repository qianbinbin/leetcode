package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class IntegerToRomanTest {
    private static final IntegerToRoman.Solution1 SOLUTION1 = new IntegerToRoman.Solution1();

    private final int NUM1 = 3;
    private final String EXPECTED1 = "III";

    private final int NUM2 = 4;
    private final String EXPECTED2 = "IV";

    private final int NUM3 = 9;
    private final String EXPECTED3 = "IX";

    private final int NUM4 = 58;
    private final String EXPECTED4 = "LVIII";

    private final int NUM5 = 1994;
    private final String EXPECTED5 = "MCMXCIV";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.intToRoman(NUM1));
        assertEquals(EXPECTED2, SOLUTION1.intToRoman(NUM2));
        assertEquals(EXPECTED3, SOLUTION1.intToRoman(NUM3));
        assertEquals(EXPECTED4, SOLUTION1.intToRoman(NUM4));
        assertEquals(EXPECTED5, SOLUTION1.intToRoman(NUM5));
    }
}