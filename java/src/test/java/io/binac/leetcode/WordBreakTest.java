package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordBreakTest {
    private static final WordBreak.Solution1 SOLUTION1 = new WordBreak.Solution1();

    private final String S1 = "leetcode";
    private final List<String> WORDDICT1 = Arrays.asList("leet", "code");
    private final boolean EXPECTED1 = true;

    private final String S2 = "applepenapple";
    private final List<String> WORDDICT2 = Arrays.asList("apple", "pen");
    private final boolean EXPECTED2 = true;

    private final String S3 = "catsandog";
    private final List<String> WORDDICT3 = Arrays.asList("cats", "dog", "sand", "and", "cat");
    private final boolean EXPECTED3 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.wordBreak(S1, WORDDICT1));
        assertEquals(EXPECTED2, SOLUTION1.wordBreak(S2, WORDDICT2));
        assertEquals(EXPECTED3, SOLUTION1.wordBreak(S3, WORDDICT3));
    }
}