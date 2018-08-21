package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RegularExpressionMatchingTest {
    private final RegularExpressionMatching.Solution1 solution1 = new RegularExpressionMatching.Solution1();

    private final RegularExpressionMatching.Solution2 solution2 = new RegularExpressionMatching.Solution2();

    private final String s1 = "aa", p1 = "a",
            s2 = "aa", p2 = "a*",
            s3 = "ab", p3 = ".*",
            s4 = "aab", p4 = "c*a*b",
            s5 = "mississippi", p5 = "mis*is*p*.";

    @Test
    void test1() {
        assertFalse(solution1.isMatch(s1, p1));
        assertTrue(solution1.isMatch(s2, p2));
        assertTrue(solution1.isMatch(s3, p3));
        assertTrue(solution1.isMatch(s4, p4));
        assertFalse(solution1.isMatch(s5, p5));
    }

    @Test
    void test2() {
        assertFalse(solution2.isMatch(s1, p1));
        assertTrue(solution2.isMatch(s2, p2));
        assertTrue(solution2.isMatch(s3, p3));
        assertTrue(solution2.isMatch(s4, p4));
        assertFalse(solution2.isMatch(s5, p5));
    }
}