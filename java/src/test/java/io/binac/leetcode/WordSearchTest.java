package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class WordSearchTest {
    private static final WordSearch.Solution1 SOLUTION1 = new WordSearch.Solution1();

    private final char[][] BOARD1 = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    private final String WORD1 = "ABCCED";
    private final boolean EXPECTED1 = true;

    private final char[][] BOARD2 = BOARD1;
    private final String WORD2 = "SEE";
    private final boolean EXPECTED2 = true;

    private final char[][] BOARD3 = BOARD1;
    private final String WORD3 = "ABCB";
    private final boolean EXPECTED3 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.exist(BOARD1, WORD1));
        assertEquals(EXPECTED2, SOLUTION1.exist(BOARD2, WORD2));
        assertEquals(EXPECTED3, SOLUTION1.exist(BOARD3, WORD3));
    }
}