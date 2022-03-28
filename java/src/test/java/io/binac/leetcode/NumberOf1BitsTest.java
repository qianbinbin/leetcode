package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class NumberOf1BitsTest {
    private static final NumberOf1Bits.Solution1 SOLUTION1 = new NumberOf1Bits.Solution1();

    private final int N1 = 0b00000000000000000000000000001011;
    private final int EXPECTED1 = 3;

    private final int N2 = 0b00000000000000000000000010000000;
    private final int EXPECTED2 = 1;

    private final int N3 = 0b11111111111111111111111111111101;
    private final int EXPECTED3 = 31;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.hammingWeight(N1));
        assertEquals(EXPECTED2, SOLUTION1.hammingWeight(N2));
        assertEquals(EXPECTED3, SOLUTION1.hammingWeight(N3));
    }
}