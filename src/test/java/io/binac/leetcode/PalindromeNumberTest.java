package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PalindromeNumberTest {
    private final PalindromeNumber.Solution1 solution1 = new PalindromeNumber.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isPalindrome(121));
        assertFalse(solution1.isPalindrome(-121));
        assertFalse(solution1.isPalindrome(10));
    }
}