package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordLadderTest {
    private final WordLadder.Solution1 solution1 = new WordLadder.Solution1();

    @Test
    void test1() {
        List<String> wordList1 = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");
        assertEquals(5, solution1.ladderLength("hit", "cog", wordList1));

        List<String> wordList2 = Arrays.asList("hot", "dot", "dog", "lot", "log");
        assertEquals(0, solution1.ladderLength("hit", "cog", wordList2));
    }
}