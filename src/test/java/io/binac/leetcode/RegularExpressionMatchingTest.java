package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RegularExpressionMatchingTest {
    private final RegularExpressionMatching.Solution1 solution1 = new RegularExpressionMatching.Solution1();

    @Test
    void test1() {
        assertFalse(solution1.isMatch("aa", "a"));
        assertTrue(solution1.isMatch("aa", "a*"));
        assertTrue(solution1.isMatch("ab", ".*"));
        assertTrue(solution1.isMatch("aab", "c*a*b"));
        assertFalse(solution1.isMatch("mississippi", "mis*is*p*."));
    }
}