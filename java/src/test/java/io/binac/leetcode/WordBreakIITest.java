package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordBreakIITest {
    private static final WordBreakII.Solution1 SOLUTION1 = new WordBreakII.Solution1();

    private final String S1 = "catsanddog";
    private final List<String> WORDDICT1 = Arrays.asList("cat", "cats", "and", "sand", "dog");
    private final List<String> EXPECTED1 = Arrays.asList("cat sand dog", "cats and dog");

    private final String S2 = "pineapplepenapple";
    private final List<String> WORDDICT2 = Arrays.asList("apple", "pen", "applepen", "pine", "pineapple");
    private final List<String> EXPECTED2 = Arrays.asList("pine apple pen apple", "pine applepen apple", "pineapple pen apple");

    private final String S3 = "catsandog";
    private final List<String> WORDDICT3 = Arrays.asList("cats", "dog", "sand", "and", "cat");
    private final List<String> EXPECTED3 = Collections.emptyList();

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.wordBreak(S1, WORDDICT1));
        assertEquals(EXPECTED2, SOLUTION1.wordBreak(S2, WORDDICT2));
        assertEquals(EXPECTED3, SOLUTION1.wordBreak(S3, WORDDICT3));
    }
}