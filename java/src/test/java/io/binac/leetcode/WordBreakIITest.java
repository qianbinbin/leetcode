package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordBreakIITest {
    private final WordBreakII.Solution1 solution1 = new WordBreakII.Solution1();

    private final String s1 = "catsanddog";
    private final List<String> wordDict1 = Arrays.asList("cat", "cats", "and", "sand", "dog");
    private final List<String> expected1 = Arrays.asList(
            "cat sand dog",
            "cats and dog");

    private final String s2 = "pineapplepenapple";
    private final List<String> wordDict2 = Arrays.asList("apple", "pen", "applepen", "pine", "pineapple");
    private final List<String> expected2 = Arrays.asList(
            "pine apple pen apple",
            "pine applepen apple",
            "pineapple pen apple");

    private final String s3 = "catsandog";
    private final List<String> wordDict3 = Arrays.asList("cats", "dog", "sand", "and", "cat");
    private final List<String> expected3 = Collections.emptyList();

    @Test
    void test1() {
        assertEquals(expected1, solution1.wordBreak(s1, wordDict1));
        assertEquals(expected2, solution1.wordBreak(s2, wordDict2));
        assertEquals(expected3, solution1.wordBreak(s3, wordDict3));
    }
}