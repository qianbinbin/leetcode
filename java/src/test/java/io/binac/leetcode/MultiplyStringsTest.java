package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MultiplyStringsTest {
    private static final MultiplyStrings.Solution1 SOLUTION1 = new MultiplyStrings.Solution1();

    private final String NUM11 = "2";
    private final String NUM12 = "3";
    private final String EXPECTED1 = "6";

    private final String NUM21 = "123";
    private final String NUM22 = "456";
    private final String EXPECTED2 = "56088";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.multiply(NUM11, NUM12));
        assertEquals(EXPECTED2, SOLUTION1.multiply(NUM21, NUM22));
    }
}