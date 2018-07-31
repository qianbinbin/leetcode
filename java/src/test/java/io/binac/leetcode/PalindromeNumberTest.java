package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PalindromeNumberTest {
    private final PalindromeNumber.Solution1 solution1 = new PalindromeNumber.Solution1();

    private final PalindromeNumber.Solution2 solution2 = new PalindromeNumber.Solution2();

    @Test
    void test1() {
        assertTrue(solution1.isPalindrome(121));
        assertFalse(solution1.isPalindrome(-121));
        assertFalse(solution1.isPalindrome(10));
    }

    @Test
    void test2() {
        assertTrue(solution2.isPalindrome(121));
        assertFalse(solution2.isPalindrome(-121));
        assertFalse(solution2.isPalindrome(10));
    }
}