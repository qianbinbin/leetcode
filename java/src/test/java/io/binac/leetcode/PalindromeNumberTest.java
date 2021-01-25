package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PalindromeNumberTest {
    private static final PalindromeNumber.Solution2 SOLUTION1 = new PalindromeNumber.Solution2();

    private final int X1 = 121;
    private final boolean EXPECTED1 = true;

    private final int X2 = -121;
    private final boolean EXPECTED2 = false;

    private final int X3 = 10;
    private final boolean EXPECTED3 = false;

    private final int X4 = -101;
    private final boolean EXPECTED4 = false;

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION1.isPalindrome(X1));
        assertEquals(EXPECTED2, SOLUTION1.isPalindrome(X2));
        assertEquals(EXPECTED3, SOLUTION1.isPalindrome(X3));
        assertEquals(EXPECTED4, SOLUTION1.isPalindrome(X4));
    }
}