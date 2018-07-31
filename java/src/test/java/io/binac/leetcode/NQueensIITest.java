package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NQueensIITest {
    private final NQueensII.Solution1 solution1 = new NQueensII.Solution1();

    @Test
    void test1() {
        assertEquals(2, solution1.totalNQueens(4));
    }
}