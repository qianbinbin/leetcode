package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CandyTest {
    private static final Candy.Solution1 SOLUTION1 = new Candy.Solution1();

    private final int[] RATINGS1 = {1, 0, 2};
    private final int EXPECTED1 = 5;

    private final int[] RATINGS2 = {1, 2, 2};
    private final int EXPECTED2 = 4;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.candy(RATINGS1));
        assertEquals(EXPECTED2, SOLUTION1.candy(RATINGS2));
    }
}