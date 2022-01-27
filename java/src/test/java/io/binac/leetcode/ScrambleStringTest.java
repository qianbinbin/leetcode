package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ScrambleStringTest {
    private static final ScrambleString.Solution1 SOLUTION1 = new ScrambleString.Solution1();
    private static final ScrambleString.Solution2 SOLUTION2 = new ScrambleString.Solution2();

    private final String S11 = "great", S12 = "rgeat";
    private final boolean EXPECTED1 = true;

    private final String S21 = "abcde", S22 = "caebd";
    private final boolean EXPECTED2 = false;

    private final String S31 = "a", S32 = "a";
    private final boolean EXPECTED3 = true;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isScramble(S11, S12));
        assertEquals(EXPECTED2, SOLUTION1.isScramble(S21, S22));
        assertEquals(EXPECTED3, SOLUTION1.isScramble(S31, S32));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.isScramble(S11, S12));
        assertEquals(EXPECTED2, SOLUTION2.isScramble(S21, S22));
        assertEquals(EXPECTED3, SOLUTION2.isScramble(S31, S32));
    }
}