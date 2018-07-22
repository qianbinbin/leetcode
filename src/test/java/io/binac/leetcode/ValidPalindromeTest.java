package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidPalindromeTest {
    private final ValidPalindrome.Solution1 solution1 = new ValidPalindrome.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isPalindrome("A man, a plan, a canal: Panama"));
        assertFalse(solution1.isPalindrome("race a car"));
    }
}