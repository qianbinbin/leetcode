package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class LongestSubstringWithoutRepeatingCharactersTest {
    private static final LongestSubstringWithoutRepeatingCharacters.Solution1 SOLUTION1 = new LongestSubstringWithoutRepeatingCharacters.Solution1();

    private final String S1 = "abcabcbb";
    private final int EXPECTED1 = 3;

    private final String S2 = "bbbbb";
    private final int EXPECTED2 = 1;

    private final String S3 = "pwwkew";
    private final int EXPECTED3 = 3;

    private final String S4 = "";
    private final int EXPECTED4 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.lengthOfLongestSubstring(S1));
        assertEquals(EXPECTED2, SOLUTION1.lengthOfLongestSubstring(S2));
        assertEquals(EXPECTED3, SOLUTION1.lengthOfLongestSubstring(S3));
        assertEquals(EXPECTED4, SOLUTION1.lengthOfLongestSubstring(S4));
    }
}