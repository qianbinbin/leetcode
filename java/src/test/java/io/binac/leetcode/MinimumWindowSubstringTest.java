package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinimumWindowSubstringTest {
    private final MinimumWindowSubstring.Solution1 solution1 = new MinimumWindowSubstring.Solution1();

    @Test
    void test1() {
        assertEquals("BANC", solution1.minWindow("ADOBECODEBANC", "ABC"));
    }
}