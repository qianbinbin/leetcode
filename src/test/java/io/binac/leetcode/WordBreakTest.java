package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordBreakTest {
    private final WordBreak.Solution1 solution1 = new WordBreak.Solution1();

    private final String s1 = "leetcode";
    private final List<String> wordDict1 = Arrays.asList("leet", "code");

    private final String s2 = "applepenapple";
    private final List<String> wordDict2 = Arrays.asList("apple", "pen");

    private final String s3 = "catsandog";
    private final List<String> wordDict3 = Arrays.asList("cats", "dog", "sand", "and", "cat");

    @Test
    void test1() {
        assertTrue(solution1.wordBreak(s1, wordDict1));
        assertTrue(solution1.wordBreak(s2, wordDict2));
        assertFalse(solution1.wordBreak(s3, wordDict3));
    }
}