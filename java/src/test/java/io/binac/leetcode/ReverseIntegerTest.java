package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseIntegerTest {
    private final ReverseInteger.Solution1 solution1 = new ReverseInteger.Solution1();

    @Test
    void test1() {
        assertEquals(321, solution1.reverse(123));
        assertEquals(-321, solution1.reverse(-123));
        assertEquals(21, solution1.reverse(120));
    }
}