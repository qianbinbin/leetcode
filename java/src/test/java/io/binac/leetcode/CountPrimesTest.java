package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CountPrimesTest {
    private static final CountPrimes.Solution1 SOLUTION1 = new CountPrimes.Solution1();

    private final int N1 = 10;
    private final int EXPECTED1 = 4;

    private final int N2 = 0;
    private final int EXPECTED2 = 0;

    private final int N3 = 1;
    private final int EXPECTED3 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.countPrimes(N1));
        assertEquals(EXPECTED2, SOLUTION1.countPrimes(N2));
        assertEquals(EXPECTED3, SOLUTION1.countPrimes(N3));
    }
}