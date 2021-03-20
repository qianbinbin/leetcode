package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SubstringWithConcatenationOfAllWordsTest {
    private static final SubstringWithConcatenationOfAllWords.Solution1 SOLUTION1 = new SubstringWithConcatenationOfAllWords.Solution1();

    private final String S1 = "barfoothefoobarman";
    private final String[] WORDS1 = {"foo", "bar"};
    private final List<Integer> EXPECTED1 = Arrays.asList(0, 9);

    private final String S2 = "wordgoodgoodgoodbestword";
    private final String[] WORDS2 = {"word", "good", "best", "word"};
    private final List<Integer> EXPECTED2 = Collections.emptyList();

    private final String S3 = "barfoofoobarthefoobarman";
    private final String[] WORDS3 = {"bar", "foo", "the"};
    private final List<Integer> EXPECTED3 = Arrays.asList(6, 9, 12);

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.findSubstring(S1, WORDS1));
        assertEquals(EXPECTED2, SOLUTION1.findSubstring(S2, WORDS2));
        assertEquals(EXPECTED3, SOLUTION1.findSubstring(S3, WORDS3));
    }
}