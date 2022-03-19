package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class EvaluateReversePolishNotationTest {
    private static final EvaluateReversePolishNotation.Solution1 SOLUTION1 = new EvaluateReversePolishNotation.Solution1();

    private final String[] TOKENS1 = {"2", "1", "+", "3", "*"};
    private final int EXPECTED1 = 9;

    private final String[] TOKENS2 = {"4", "13", "5", "/", "+"};
    private final int EXPECTED2 = 6;

    private final String[] TOKENS3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    private final int EXPECTED3 = 22;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.evalRPN(TOKENS1));
        assertEquals(EXPECTED2, SOLUTION1.evalRPN(TOKENS2));
        assertEquals(EXPECTED3, SOLUTION1.evalRPN(TOKENS3));
    }
}