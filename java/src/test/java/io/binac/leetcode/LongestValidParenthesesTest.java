package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestValidParenthesesTest {
    private final LongestValidParentheses.Solution1 solution1 = new LongestValidParentheses.Solution1();

    private final LongestValidParentheses.Solution2 solution2 = new LongestValidParentheses.Solution2();

    private final LongestValidParentheses.Solution3 solution3 = new LongestValidParentheses.Solution3();

    @Test
    void test1() {
        assertEquals(2, solution1.longestValidParentheses("(()"));
        assertEquals(4, solution1.longestValidParentheses(")()())"));
    }

    @Test
    void test2() {
        assertEquals(2, solution2.longestValidParentheses("(()"));
        assertEquals(4, solution2.longestValidParentheses(")()())"));
    }

    @Test
    void test3() {
        assertEquals(2, solution3.longestValidParentheses("(()"));
        assertEquals(4, solution3.longestValidParentheses(")()())"));
    }
}