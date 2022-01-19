package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PlusOneTest {
    private static final PlusOne.Solution1 SOLUTION1 = new PlusOne.Solution1();

    private final int[] DIGITS1 = {1, 2, 3};
    private final int[] EXPECTED1 = {1, 2, 4};

    private final int[] DIGITS2 = {4, 3, 2, 1};
    private final int[] EXPECTED2 = {4, 3, 2, 2};

    private final int[] DIGITS3 = {9};
    private final int[] EXPECTED3 = {1, 0};


    @Test
    void test1() {
        assertArrayEquals(EXPECTED1, SOLUTION1.plusOne(DIGITS1));
        assertArrayEquals(EXPECTED2, SOLUTION1.plusOne(DIGITS2));
        assertArrayEquals(EXPECTED3, SOLUTION1.plusOne(DIGITS3));
    }
}