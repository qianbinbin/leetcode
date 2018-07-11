package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DecodeWaysTest {
    private final DecodeWays.Solution1 solution1 = new DecodeWays.Solution1();

    @Test
    void test1() {
        assertEquals(2, solution1.numDecodings("12"));
        assertEquals(3, solution1.numDecodings("226"));
    }
}