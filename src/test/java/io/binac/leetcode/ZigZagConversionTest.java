package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ZigZagConversionTest {
    private final ZigZagConversion.Solution1 solution1 = new ZigZagConversion.Solution1();

    @Test
    void test1() {
        assertEquals("PAHNAPLSIIGYIR", solution1.convert("PAYPALISHIRING", 3));
        assertEquals("PINALSIGYAHRPI", solution1.convert("PAYPALISHIRING", 4));
    }
}