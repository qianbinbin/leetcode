package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class LongestSubstringWithoutRepeatingCharactersTest {
    private final LongestSubstringWithoutRepeatingCharacters.Solution1 solution1 = new LongestSubstringWithoutRepeatingCharacters.Solution1();

    @Test
    void test1() {
        assertEquals(3, solution1.lengthOfLongestSubstring("abcabcbb"));
        assertEquals(1, solution1.lengthOfLongestSubstring("bbbbb"));
        assertEquals(3, solution1.lengthOfLongestSubstring("pwwkew"));
    }

    @Test
    void test1End() {
        assertEquals(2, solution1.lengthOfLongestSubstring("au"));
    }

    @Test
    void test1Duplicate() {
        assertEquals(2, solution1.lengthOfLongestSubstring("abba"));
    }
}