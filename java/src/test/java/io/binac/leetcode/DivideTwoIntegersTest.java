package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DivideTwoIntegersTest {
    private final DivideTwoIntegers.Solution1 solution1 = new DivideTwoIntegers.Solution1();

    @Test
    void test1() {
        assertEquals(3, solution1.divide(10, 3));
        assertEquals(-2, solution1.divide(7, -3));
    }
}