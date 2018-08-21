package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniquePathsIITest {
    private final UniquePathsII.Solution1 solution1 = new UniquePathsII.Solution1();

    private final int obstacleGrid[][] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    private final int expected = 2;

    @Test
    void test1() {
        assertEquals(expected, solution1.uniquePathsWithObstacles(obstacleGrid));
    }
}