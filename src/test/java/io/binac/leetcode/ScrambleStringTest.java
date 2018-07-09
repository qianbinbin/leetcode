package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ScrambleStringTest {
    private final ScrambleString.Solution1 solution1 = new ScrambleString.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isScramble("great", "rgeat"));
        assertFalse(solution1.isScramble("abcde", "caebd"));
    }
}