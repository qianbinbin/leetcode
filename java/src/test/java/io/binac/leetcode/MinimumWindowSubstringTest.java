package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinimumWindowSubstringTest {
    private static final MinimumWindowSubstring.Solution1 SOLUTION1 = new MinimumWindowSubstring.Solution1();

    private final String S1 = "ADOBECODEBANC", T1 = "ABC", EXPECTED1 = "BANC";

    private final String S2 = "a", T2 = "a", EXPECTED2 = "a";

    private final String S3 = "a", T3 = "aa", EXPECTED3 = "";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.minWindow(S1, T1));
        assertEquals(EXPECTED2, SOLUTION1.minWindow(S2, T2));
        assertEquals(EXPECTED3, SOLUTION1.minWindow(S3, T3));
    }
}