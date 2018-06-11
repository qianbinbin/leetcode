package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class WildcardMatchingTest {
    private final WildcardMatching.Solution1 solution1 = new WildcardMatching.Solution1();

    @Test
    void test1() {
        assertFalse(solution1.isMatch("aa", "a"));
        assertTrue(solution1.isMatch("aa", "*"));
        assertFalse(solution1.isMatch("cb", "?a"));
        assertTrue(solution1.isMatch("adceb", "*a*b"));
        assertFalse(solution1.isMatch("acdcb", "a*c?b"));
    }
}