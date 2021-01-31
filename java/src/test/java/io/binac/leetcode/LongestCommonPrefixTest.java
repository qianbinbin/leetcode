package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestCommonPrefixTest {
    private static final LongestCommonPrefix.Solution1 SOLUTION1 = new LongestCommonPrefix.Solution1();

    private final String[] STRS1 = {"flower", "flow", "flight"};
    private final String EXPECTED1 = "fl";

    private final String[] STRS2 = {"dog", "racecar", "car"};
    private final String EXPECTED2 = "";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.longestCommonPrefix(STRS1));
        assertEquals(EXPECTED2, SOLUTION1.longestCommonPrefix(STRS2));
    }
}