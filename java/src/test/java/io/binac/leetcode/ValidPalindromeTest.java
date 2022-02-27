package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidPalindromeTest {
    private static final ValidPalindrome.Solution1 SOLUTION1 = new ValidPalindrome.Solution1();

    private final String S1 = "A man, a plan, a canal: Panama";
    private final boolean EXPECTED1 = true;

    private final String S2 = "race a car";
    private final boolean EXPECTED2 = false;

    private final String S3 = " ";
    private final boolean EXPECTED3 = true;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isPalindrome(S1));
        assertEquals(EXPECTED2, SOLUTION1.isPalindrome(S2));
        assertEquals(EXPECTED3, SOLUTION1.isPalindrome(S3));
    }
}