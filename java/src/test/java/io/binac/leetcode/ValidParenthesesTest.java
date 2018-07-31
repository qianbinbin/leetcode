package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidParenthesesTest {
    private final ValidParentheses.Solution1 solution1 = new ValidParentheses.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isValid("()"));
        assertTrue(solution1.isValid("()[]{}"));
        assertFalse(solution1.isValid("(]"));
        assertFalse(solution1.isValid("([)]"));
        assertTrue(solution1.isValid("{[]}"));
    }
}