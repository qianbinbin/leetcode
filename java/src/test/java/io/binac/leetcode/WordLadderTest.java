package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordLadderTest {
    private static final WordLadder.Solution1 SOLUTION1 = new WordLadder.Solution1();

    private final String BEGINWORD1 = "hit", ENDWORD1 = "cog";
    private final List<String> WORDLIST1 = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");
    private final int EXPECTED1 = 5;

    private final String BEGINWORD2 = "hit", ENDWORD2 = "cog";
    private final List<String> WORDLIST2 = Arrays.asList("hot", "dot", "dog", "lot", "log");
    private final int EXPECTED2 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.ladderLength(BEGINWORD1, ENDWORD1, WORDLIST1));
        assertEquals(EXPECTED2, SOLUTION1.ladderLength(BEGINWORD2, ENDWORD2, WORDLIST2));
    }
}