package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestCommonPrefixTest {
    private final LongestCommonPrefix.Solution1 solution1 = new LongestCommonPrefix.Solution1();

    @Test
    void test1() {
        String strs1[] = {"flower", "flow", "flight"};
        assertEquals("fl", solution1.longestCommonPrefix(strs1));
        String strs2[] = {"dog", "racecar", "car"};
        assertEquals("", solution1.longestCommonPrefix(strs2));
    }
}