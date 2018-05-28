package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class GenerateParenthesesTest {
    private final GenerateParentheses.Solution1 solution1 = new GenerateParentheses.Solution1();

    @Test
    void test1() {
        List<String> result = solution1.generateParenthesis(3);
        List<String> expected = Arrays.asList("((()))", "(()())", "(())()", "()(())", "()()()");
        assertEquals(expected, result);
    }
}