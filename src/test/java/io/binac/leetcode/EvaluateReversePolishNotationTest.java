package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class EvaluateReversePolishNotationTest {

    private final EvaluateReversePolishNotation.Solution1 solution1 = new EvaluateReversePolishNotation.Solution1();

    private final String tokens1[] = {"2", "1", "+", "3", "*"};

    private final int expected1 = 9;

    private final String tokens2[] = {"4", "13", "5", "/", "+"};

    private final int expected2 = 6;

    private final String tokens3[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    private final int expected3 = 22;

    @Test
    void test1() {
        assertEquals(expected1, solution1.evalRPN(tokens1));
        assertEquals(expected2, solution1.evalRPN(tokens2));
        assertEquals(expected3, solution1.evalRPN(tokens3));
    }
}