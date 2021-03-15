package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class GenerateParenthesesTest {
    private static final GenerateParentheses.Solution1 SOLUTION1 = new GenerateParentheses.Solution1();

    private final int N1 = 3;
    private final List<String> EXPECTED1 = Arrays.asList("((()))", "(()())", "(())()", "()(())", "()()()");

    private final int N2 = 1;
    private final List<String> EXPECTED2 = Collections.singletonList("()");

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.generateParenthesis(N1));
        assertEquals(EXPECTED2, SOLUTION1.generateParenthesis(N2));
    }
}