package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniquePathsIITest {
    private static final UniquePathsII.Solution1 SOLUTION1 = new UniquePathsII.Solution1();

    private final int[][] OBSTACLEGRID1 = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    private final int EXPECTED1 = 2;

    private final int[][] OBSTACLEGRID2 = {
            {0, 1},
            {0, 0}
    };
    private final int EXPECTED2 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.uniquePathsWithObstacles(OBSTACLEGRID1));
        assertEquals(EXPECTED2, SOLUTION1.uniquePathsWithObstacles(OBSTACLEGRID2));
    }
}