package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniquePathsIITest {
    private final UniquePathsII.Solution1 solution1 = new UniquePathsII.Solution1();

    @Test
    void test1() {
        int obstacleGrid[][] = {
                {0, 0, 0},
                {0, 1, 0},
                {0, 0, 0}
        };
        assertEquals(2, solution1.uniquePathsWithObstacles(obstacleGrid));
    }
}