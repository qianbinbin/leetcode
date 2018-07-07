package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class WordSearchTest {
    private final WordSearch.Solution1 solution1 = new WordSearch.Solution1();

    @Test
    void test1() {
        char board[][] = {
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
        };
        assertTrue(solution1.exist(board, "ABCCED"));
        assertTrue(solution1.exist(board, "SEE"));
        assertFalse(solution1.exist(board, "ABCB"));
    }
}