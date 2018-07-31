package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PlusOneTest {
    private final PlusOne.Solution1 solution1 = new PlusOne.Solution1();

    @Test
    void test1() {
        int digits1[] = {1, 2, 3};
        int expected1[] = {1, 2, 4};
        assertArrayEquals(expected1, solution1.plusOne(digits1));

        int digits2[] = {4, 3, 2, 1};
        int expected2[] = {4, 3, 2, 2};
        assertArrayEquals(expected2, solution1.plusOne(digits2));
    }
}