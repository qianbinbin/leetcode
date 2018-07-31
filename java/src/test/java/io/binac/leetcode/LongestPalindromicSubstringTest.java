package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestPalindromicSubstringTest {
    private final LongestPalindromicSubstring.Solution1 solution1 = new LongestPalindromicSubstring.Solution1();

    @Test
    void test1() {
        assertEquals("aba", solution1.longestPalindrome("babad"));
        assertEquals("bb", solution1.longestPalindrome("cbbd"));
    }
}