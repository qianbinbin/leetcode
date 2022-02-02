package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InterleavingStringTest {
    private static final InterleavingString.Solution1 SOLUTION1 = new InterleavingString.Solution1();

    private final String S11 = "aabcc", S12 = "dbbca", S13 = "aadbbcbcac";
    private final boolean EXPECTED1 = true;

    private final String S21 = "aabcc", S22 = "dbbca", S23 = "aadbbbaccc";
    private final boolean EXPECTED2 = false;

    private final String S31 = "", S32 = "", S33 = "";
    private final boolean EXPECTED3 = true;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isInterleave(S11, S12, S13));
        assertEquals(EXPECTED2, SOLUTION1.isInterleave(S21, S22, S23));
        assertEquals(EXPECTED3, SOLUTION1.isInterleave(S31, S32, S33));
    }
}