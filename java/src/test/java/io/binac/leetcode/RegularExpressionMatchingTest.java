package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RegularExpressionMatchingTest {
    private final RegularExpressionMatching.Solution1 solution1 = new RegularExpressionMatching.Solution1();

    private final RegularExpressionMatching.Solution2 solution2 = new RegularExpressionMatching.Solution2();

    @Test
    void test1() {
        assertFalse(solution1.isMatch("aa", "a"));
        assertTrue(solution1.isMatch("aa", "a*"));
        assertTrue(solution1.isMatch("ab", ".*"));
        assertTrue(solution1.isMatch("aab", "c*a*b"));
        assertFalse(solution1.isMatch("mississippi", "mis*is*p*."));
    }

    @Test
    void test2() {
        assertFalse(solution2.isMatch("aa", "a"));
        assertTrue(solution2.isMatch("aa", "a*"));
        assertTrue(solution2.isMatch("ab", ".*"));
        assertTrue(solution2.isMatch("aab", "c*a*b"));
        assertFalse(solution2.isMatch("mississippi", "mis*is*p*."));
    }
}