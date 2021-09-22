package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

class InsertIntervalTest {
    private static final InsertInterval.Solution1 SOLUTION1 = new InsertInterval.Solution1();

    private final int[][] INTERVALS1 = {{1, 3}, {6, 9}};
    private final int[] NEWINTERVAL1 = {2, 5};
    private final int[][] EXPECTED1 = {{1, 5}, {6, 9}};

    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.insert(INTERVALS1, NEWINTERVAL1));
    }
}