package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LengthOfLastWordTest {
    private final LengthOfLastWord.Solution1 solution1 = new LengthOfLastWord.Solution1();

    @Test
    void test1() {
        assertEquals(5, solution1.lengthOfLastWord("Hello World"));
    }
}