package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidNumberTest {
    private final ValidNumber.Solution1 solution1 = new ValidNumber.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isNumber("0"));
        assertTrue(solution1.isNumber(" 0.1 "));
        assertFalse(solution1.isNumber("abc"));
        assertFalse(solution1.isNumber("1 a"));
        assertTrue(solution1.isNumber("2e10"));
    }
}