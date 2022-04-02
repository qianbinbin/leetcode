package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WordSearchIITest {
    private static final WordSearchII.Solution1 SOLUTION1 = new WordSearchII.Solution1();

    private final char[][] BOARD1 = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    private final String[] WORDS1 = {"oath", "pea", "eat", "rain"};
    private final List<String> EXPECTED1 = Arrays.asList("oath", "eat");

    private final char[][] BOARD2 = {{'a', 'b'}, {'c', 'd'}};
    private final String[] WORDS2 = {"abcb"};
    private final List<String> EXPECTED2 = Collections.emptyList();

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.findWords(BOARD1, WORDS1));
        assertEquals(EXPECTED2, SOLUTION1.findWords(BOARD2, WORDS2));
    }
}