package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidNumberTest {
    private static final ValidNumber.Solution1 SOLUTION1 = new ValidNumber.Solution1();

    private final String S1 = "0";
    private final boolean EXPECTED1 = true;

    private final String S2 = "e";
    private final boolean EXPECTED2 = false;

    private final String S3 = ".";
    private final boolean EXPECTED3 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isNumber(S1));
        assertEquals(EXPECTED2, SOLUTION1.isNumber(S2));
        assertEquals(EXPECTED3, SOLUTION1.isNumber(S3));
    }
}