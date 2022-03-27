package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FactorialTrailingZeroesTest {
    private static final FactorialTrailingZeroes.Solution1 SOLUTION1 = new FactorialTrailingZeroes.Solution1();

    private final int N1 = 3;
    private final int EXPECTED1 = 0;

    private final int N2 = 5;
    private final int EXPECTED2 = 1;

    private final int N3 = 0;
    private final int EXPECTED3 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.trailingZeroes(N1));
        assertEquals(EXPECTED2, SOLUTION1.trailingZeroes(N2));
        assertEquals(EXPECTED3, SOLUTION1.trailingZeroes(N3));
    }
}