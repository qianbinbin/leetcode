package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseWordsInAStringTest {

    private final ReverseWordsInAString.Solution1 solution1 = new ReverseWordsInAString.Solution1();

    private final String s = "the sky is blue";

    private final String expected = "blue is sky the";

    @Test
    void test1() {
        assertEquals(expected, solution1.reverseWords(s));
    }
}