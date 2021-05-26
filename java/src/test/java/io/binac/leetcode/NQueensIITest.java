package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NQueensIITest {
    private static final NQueensII.Solution1 SOLUTION1 = new NQueensII.Solution1();

    private final int N1 = 4, EXPECTED1 = 2;

    private final int N2 = 1, EXPECTED2 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.totalNQueens(N1));
        assertEquals(EXPECTED2, SOLUTION1.totalNQueens(N2));
    }
}