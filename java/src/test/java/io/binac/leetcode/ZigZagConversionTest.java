package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ZigZagConversionTest {
    private static final ZigZagConversion.Solution1 SOLUTION1 = new ZigZagConversion.Solution1();

    private final String S1 = "PAYPALISHIRING";
    private final int NUM_ROWS1 = 3;
    private final String EXPECTED1 = "PAHNAPLSIIGYIR";

    private final String S2 = "PAYPALISHIRING";
    private final int NUM_ROWS2 = 4;
    private final String EXPECTED2 = "PINALSIGYAHRPI";

    private final String S3 = "A";
    private final int NUM_ROWS3 = 1;
    private final String EXPECTED3 = "A";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.convert(S1, NUM_ROWS1));
        assertEquals(EXPECTED2, SOLUTION1.convert(S2, NUM_ROWS2));
        assertEquals(EXPECTED3, SOLUTION1.convert(S3, NUM_ROWS3));
    }
}