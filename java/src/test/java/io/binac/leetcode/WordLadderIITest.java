package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordLadderIITest {
    private static final WordLadderII.Solution1 SOLUTION1 = new WordLadderII.Solution1();

    private final String BEGINWORD1 = "hit", ENDWORD1 = "cog";
    private final List<String> WORDLIST1 = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");
    private final List<List<String>> EXPECTED1 = Arrays.asList(
            Arrays.asList("hit", "hot", "lot", "log", "cog"),
            Arrays.asList("hit", "hot", "dot", "dog", "cog")
    );

    private final String BEGINWORD2 = "hit", ENDWORD2 = "cog";
    private final List<String> WORDLIST2 = Arrays.asList("hot", "dot", "dog", "lot", "log");
    private final List<List<String>> EXPECTED2 = Collections.emptyList();

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.findLadders(BEGINWORD1, ENDWORD1, WORDLIST1));
        assertEquals(EXPECTED2, SOLUTION1.findLadders(BEGINWORD2, ENDWORD2, WORDLIST2));
    }
}