package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SubstringWithConcatenationOfAllWordsTest {
    private final SubstringWithConcatenationOfAllWords.Solution1 solution1 = new SubstringWithConcatenationOfAllWords.Solution1();

    @Test
    void test1() {
        String words1[] = {"foo", "bar"};
        List<Integer> result1 = solution1.findSubstring("barfoothefoobarman", words1);
        List<Integer> expected1 = Arrays.asList(0, 9);
        assertEquals(expected1, result1);

        String words2[] = {"word", "student"};
        List<Integer> result2 = solution1.findSubstring("wordgoodstudentgoodword", words2);
        List<Integer> expected2 = Collections.emptyList();
        assertEquals(expected2, result2);
    }
}