package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestValidParenthesesTest {
    private static final LongestValidParentheses.Solution1 SOLUTION1 = new LongestValidParentheses.Solution1();
    private static final LongestValidParentheses.Solution2 SOLUTION2 = new LongestValidParentheses.Solution2();
    private static final LongestValidParentheses.Solution3 SOLUTION3 = new LongestValidParentheses.Solution3();

    private final String S1 = "(()";
    private final int EXPECTED1 = 2;

    private final String S2 = ")()())";
    private final int EXPECTED2 = 4;

    private final String S3 = "";
    private final int EXPECTED3 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.longestValidParentheses(S1));
        assertEquals(EXPECTED2, SOLUTION1.longestValidParentheses(S2));
        assertEquals(EXPECTED3, SOLUTION1.longestValidParentheses(S3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.longestValidParentheses(S1));
        assertEquals(EXPECTED2, SOLUTION2.longestValidParentheses(S2));
        assertEquals(EXPECTED3, SOLUTION2.longestValidParentheses(S3));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.longestValidParentheses(S1));
        assertEquals(EXPECTED2, SOLUTION3.longestValidParentheses(S2));
        assertEquals(EXPECTED3, SOLUTION3.longestValidParentheses(S3));
    }
}