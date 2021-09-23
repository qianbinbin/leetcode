package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LengthOfLastWordTest {
    private static final LengthOfLastWord.Solution1 SOLUTION1 = new LengthOfLastWord.Solution1();

    private final String S1 = "Hello World";
    private final int EXPECTED1 = 5;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.lengthOfLastWord(S1));
    }
}