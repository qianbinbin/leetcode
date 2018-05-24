package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class IntegerToRomanTest {
    private final IntegerToRoman.Solution1 solution1 = new IntegerToRoman.Solution1();

    @Test
    void test1() {
        assertEquals("III", solution1.intToRoman(3));
        assertEquals("IV", solution1.intToRoman(4));
        assertEquals("IX", solution1.intToRoman(9));
        assertEquals("LVIII", solution1.intToRoman(58));
        assertEquals("MCMXCIV", solution1.intToRoman(1994));
    }
}