package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PalindromePartitioningIITest {
    private static PalindromePartitioningII.Solution1 SOLUTION1 = new PalindromePartitioningII.Solution1();
    private static PalindromePartitioningII.Solution2 SOLUTION2 = new PalindromePartitioningII.Solution2();

    private final String S1 = "aab";
    private final int EXPECTED1 = 1;

    private final String S2 = "a";
    private final int EXPECTED2 = 0;

    private final String S3 = "ab";
    private final int EXPECTED3 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.minCut(S1));
        assertEquals(EXPECTED2, SOLUTION1.minCut(S2));
        assertEquals(EXPECTED3, SOLUTION1.minCut(S3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.minCut(S1));
        assertEquals(EXPECTED2, SOLUTION2.minCut(S2));
        assertEquals(EXPECTED3, SOLUTION2.minCut(S3));
    }
}