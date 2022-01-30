package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DecodeWaysTest {
    private static final DecodeWays.Solution1 SOLUTION1 = new DecodeWays.Solution1();

    private final String S1 = "12";
    private final int EXPECTED1 = 2;

    private final String S2 = "226";
    private final int EXPECTED2 = 3;

    private final String S3 = "06";
    private final int EXPECTED3 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.numDecodings(S1));
        assertEquals(EXPECTED2, SOLUTION1.numDecodings(S2));
        assertEquals(EXPECTED3, SOLUTION1.numDecodings(S3));
    }
}