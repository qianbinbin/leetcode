package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestValidParenthesesTest {
    private final LongestValidParentheses.Solution1 solution1 = new LongestValidParentheses.Solution1();

    @Test
    void test1() {
        assertEquals(2, solution1.longestValidParentheses("(()"));
        assertEquals(4, solution1.longestValidParentheses(")()())"));
    }
}