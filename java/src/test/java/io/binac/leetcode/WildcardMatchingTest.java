package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class WildcardMatchingTest {
    private final WildcardMatching.Solution1 solution1 = new WildcardMatching.Solution1();

    private final WildcardMatching.Solution2 solution2 = new WildcardMatching.Solution2();

    @Test
    void test1() {
        assertFalse(solution1.isMatch("aa", "a"));
        assertTrue(solution1.isMatch("aa", "*"));
        assertFalse(solution1.isMatch("cb", "?a"));
        assertTrue(solution1.isMatch("adceb", "*a*b"));
        assertFalse(solution1.isMatch("acdcb", "a*c?b"));
    }

    @Test
    void test2() {
        assertFalse(solution2.isMatch("aa", "a"));
        assertTrue(solution2.isMatch("aa", "*"));
        assertFalse(solution2.isMatch("cb", "?a"));
        assertTrue(solution2.isMatch("adceb", "*a*b"));
        assertFalse(solution2.isMatch("acdcb", "a*c?b"));
    }
}