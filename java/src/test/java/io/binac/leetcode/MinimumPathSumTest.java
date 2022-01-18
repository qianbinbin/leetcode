package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinimumPathSumTest {
    private static final MinimumPathSum.Solution1 SOLUTION1 = new MinimumPathSum.Solution1();

    private final int[][] GRID1 = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    private final int EXPECTED1 = 7;

    private final int[][] GRID2 = {
            {1, 2, 3},
            {4, 5, 6}
    };
    private final int EXPECTED2 = 12;


    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.minPathSum(GRID1));
        assertEquals(EXPECTED2, SOLUTION1.minPathSum(GRID2));
    }
}