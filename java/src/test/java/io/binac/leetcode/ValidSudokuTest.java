package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidSudokuTest {
    private static final ValidSudoku.Solution1 SOLUTION1 = new ValidSudoku.Solution1();

    private final char[][] BOARD1 = {
            "53..7....".toCharArray(),
            "6..195...".toCharArray(),
            ".98....6.".toCharArray(),
            "8...6...3".toCharArray(),
            "4..8.3..1".toCharArray(),
            "7...2...6".toCharArray(),
            ".6....28.".toCharArray(),
            "...419..5".toCharArray(),
            "....8..79".toCharArray()
    };
    private final boolean EXPECTED1 = true;

    private final char[][] BOARD2 = {
            "83..7....".toCharArray(),
            "6..195...".toCharArray(),
            ".98....6.".toCharArray(),
            "8...6...3".toCharArray(),
            "4..8.3..1".toCharArray(),
            "7...2...6".toCharArray(),
            ".6....28.".toCharArray(),
            "...419..5".toCharArray(),
            "....8..79".toCharArray()
    };
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isValidSudoku(BOARD1));
        assertEquals(EXPECTED2, SOLUTION1.isValidSudoku(BOARD2));
    }
}