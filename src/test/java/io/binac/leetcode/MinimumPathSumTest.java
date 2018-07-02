package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinimumPathSumTest {
    private final MinimumPathSum.Solution1 solution1 = new MinimumPathSum.Solution1();

    @Test
    void test1() {
        int grid[][] = {
                {1, 3, 1},
                {1, 5, 1},
                {4, 2, 1}
        };
        assertEquals(7, solution1.minPathSum(grid));
    }
}