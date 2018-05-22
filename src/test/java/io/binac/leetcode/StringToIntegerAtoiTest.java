package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StringToIntegerAtoiTest {
    private final StringToIntegerAtoi.Solution1 solution1 = new StringToIntegerAtoi.Solution1();

    @Test
    void test1() {
        assertEquals(42, solution1.myAtoi("42"));
        assertEquals(-42, solution1.myAtoi("-42"));
        assertEquals(4193, solution1.myAtoi("4193 with words"));
        assertEquals(0, solution1.myAtoi("words and 987"));
        assertEquals(-2147483648, solution1.myAtoi("-91283472332"));
    }
}