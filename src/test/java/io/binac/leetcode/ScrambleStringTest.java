package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ScrambleStringTest {
    private final ScrambleString.Solution1 solution1 = new ScrambleString.Solution1();

    private final ScrambleString.Solution2 solution2 = new ScrambleString.Solution2();

    @Test
    void test1() {
        assertTrue(solution1.isScramble("great", "rgeat"));
        assertFalse(solution1.isScramble("abcde", "caebd"));
    }

    @Test
    void test2() {
        assertTrue(solution2.isScramble("great", "rgeat"));
        assertFalse(solution2.isScramble("abcde", "caebd"));
    }
}