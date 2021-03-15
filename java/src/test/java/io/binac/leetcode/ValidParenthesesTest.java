package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidParenthesesTest {
    private static final ValidParentheses.Solution1 SOLUTION1 = new ValidParentheses.Solution1();

    private final String S1 = "()";
    private final boolean EXPECTED1 = true;

    private final String S2 = "()[]{}";
    private final boolean EXPECTED2 = true;

    private final String S3 = "(]";
    private final boolean EXPECTED3 = false;

    private final String S4 = "([)]";
    private final boolean EXPECTED4 = false;

    private final String S5 = "{[]}";
    private final boolean EXPECTED5 = true;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isValid(S1));
        assertEquals(EXPECTED2, SOLUTION1.isValid(S2));
        assertEquals(EXPECTED3, SOLUTION1.isValid(S3));
        assertEquals(EXPECTED4, SOLUTION1.isValid(S4));
        assertEquals(EXPECTED5, SOLUTION1.isValid(S5));
    }
}