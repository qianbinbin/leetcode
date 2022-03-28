package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseBitsTest {
    private static final ReverseBits.Solution1 SOLUTION1 = new ReverseBits.Solution1();
    private static final ReverseBits.Solution2 SOLUTION2 = new ReverseBits.Solution2();

    private final int N1 = 0b00000010100101000001111010011100;
    private final int EXPECTED1 = 0b00111001011110000010100101000000;

    private final int N2 = 0b11111111111111111111111111111101;
    private final int EXPECTED2 = 0b10111111111111111111111111111111;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.reverseBits(N1));
        assertEquals(EXPECTED2, SOLUTION1.reverseBits(N2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.reverseBits(N1));
        assertEquals(EXPECTED2, SOLUTION2.reverseBits(N2));
    }
}