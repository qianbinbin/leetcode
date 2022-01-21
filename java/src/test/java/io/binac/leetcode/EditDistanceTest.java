package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class EditDistanceTest {
    private static final EditDistance.Solution1 SOLUTION1 = new EditDistance.Solution1();

    private final String WORD11 = "horse", WORD12 = "ros";
    private final int EXPECTED1 = 3;

    private final String WORD21 = "intention", WORD22 = "execution";
    private final int EXPECTED2 = 5;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.minDistance(WORD11, WORD12));
        assertEquals(EXPECTED2, SOLUTION1.minDistance(WORD21, WORD22));
    }
}