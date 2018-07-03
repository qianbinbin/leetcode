package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SqrtXTest {
    private final SqrtX.Solution1 solution1 = new SqrtX.Solution1();

    private final SqrtX.Solution2 solution2 = new SqrtX.Solution2();

    @Test
    void test1() {
        assertEquals(2, solution1.mySqrt(4));
        assertEquals(2, solution1.mySqrt(8));
    }

    @Test
    void test2() {
        assertEquals(2, solution2.mySqrt(4));
        assertEquals(2, solution2.mySqrt(8));
    }
}