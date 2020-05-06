package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class LongestSubstringWithoutRepeatingCharactersTest {
    private final LongestSubstringWithoutRepeatingCharacters.Solution1 solution1 = new LongestSubstringWithoutRepeatingCharacters.Solution1();

    private final String S1 = "abcabcbb";
    private final int EXPECTED1 = 3;
    private final String S2 = "bbbbb";
    private final int EXPECTED2 = 1;
    private final String S3 = "pwwkew";
    private final int EXPECTED3 = 3;
    private final String S_END = "au";
    private final int EXPECTED_END = 2;
    private final String S_DUP = "abba";
    private final int EXPECTED_DUP = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, solution1.lengthOfLongestSubstring(S1));
        assertEquals(EXPECTED2, solution1.lengthOfLongestSubstring(S2));
        assertEquals(EXPECTED3, solution1.lengthOfLongestSubstring(S3));
    }

    @Test
    void test1End() {
        assertEquals(EXPECTED_END, solution1.lengthOfLongestSubstring(S_END));
    }

    @Test
    void test1Duplicate() {
        assertEquals(EXPECTED_DUP, solution1.lengthOfLongestSubstring(S_DUP));
    }
}