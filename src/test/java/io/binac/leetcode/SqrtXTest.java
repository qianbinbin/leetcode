package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SqrtXTest {
    private final SqrtX.Solution1 solution1 = new SqrtX.Solution1();

    @Test
    void test1() {
        assertEquals(2, solution1.mySqrt(4));
        assertEquals(2, solution1.mySqrt(8));
    }
}