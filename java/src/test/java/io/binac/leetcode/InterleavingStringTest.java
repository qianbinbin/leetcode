package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InterleavingStringTest {
    private final InterleavingString.Solution1 solution1 = new InterleavingString.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
        assertFalse(solution1.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    }
}