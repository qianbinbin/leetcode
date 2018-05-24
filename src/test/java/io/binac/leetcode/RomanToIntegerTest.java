package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RomanToIntegerTest {
    private final RomanToInteger.Solution1 solution1 = new RomanToInteger.Solution1();

    @Test
    void test1() {
        assertEquals(3, solution1.romanToInt("III"));
        assertEquals(4, solution1.romanToInt("IV"));
        assertEquals(9, solution1.romanToInt("IX"));
        assertEquals(58, solution1.romanToInt("LVIII"));
        assertEquals(1994, solution1.romanToInt("MCMXCIV"));
    }
}