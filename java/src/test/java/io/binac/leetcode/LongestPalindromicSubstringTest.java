package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestPalindromicSubstringTest {
    private static final LongestPalindromicSubstring.Solution1 SOLUTION1 = new LongestPalindromicSubstring.Solution1();

    private final String S1 = "babad";
    private final String EXPECTED1 = "bab";

    private final String S2 = "cbbd";
    private final String EXPECTED2 = "bb";

    private final String S3 = "a";
    private final String EXPECTED3 = "a";

    private final String S4 = "ac";
    private final String EXPECTED4 = "a";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.longestPalindrome(S1));
        assertEquals(EXPECTED2, SOLUTION1.longestPalindrome(S2));
        assertEquals(EXPECTED3, SOLUTION1.longestPalindrome(S3));
        assertEquals(EXPECTED4, SOLUTION1.longestPalindrome(S4));
    }
}