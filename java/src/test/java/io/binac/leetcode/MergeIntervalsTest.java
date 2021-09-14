package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MergeIntervalsTest {
    private static final MergeIntervals.Solution1 SOLUTION1 = new MergeIntervals.Solution1();

    private final int[][] INTERVALS1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    private final int[][] EXPECTED1 = {{1, 6}, {8, 10}, {15, 18}};

    private final int[][] INTERVALS2 = {{1, 4}, {4, 5}};
    private final int[][] EXPECTED2 = {{1, 5}};

    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.merge(INTERVALS1));
        assertArrayEquals(EXPECTED2, SOLUTION1.merge(INTERVALS2));
    }
}