package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordLadderIITest {
    private final WordLadderII.Solution1 solution1 = new WordLadderII.Solution1();

    @Test
    void test1() {
        List<String> wordList1 = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");
        List<List<String>> expected1 = Arrays.asList(
                Arrays.asList("hit", "hot", "lot", "log", "cog"),
                Arrays.asList("hit", "hot", "dot", "dog", "cog")
        );
        assertEquals(expected1, solution1.findLadders("hit", "cog", wordList1));

        List<String> wordList2 = Arrays.asList("hot", "dot", "dog", "lot", "log");
        assertEquals(Collections.emptyList(), solution1.findLadders("hit", "cog", wordList2));
    }
}