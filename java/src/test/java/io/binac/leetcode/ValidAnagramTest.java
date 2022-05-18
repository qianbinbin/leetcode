package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidAnagramTest {
    private static final ValidAnagram.Solution1 SOLUTION1 = new ValidAnagram.Solution1();

    private final String S1 = "anagram", T1 = "nagaram";
    private final boolean EXPECTED1 = true;

    private final String S2 = "rat", T2 = "car";
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isAnagram(S1, T1));
        assertEquals(EXPECTED2, SOLUTION1.isAnagram(S2, T2));
    }
}