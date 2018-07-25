package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PalindromePartitioningIITest {
    private PalindromePartitioningII.Solution1 solution1 = new PalindromePartitioningII.Solution1();

    private PalindromePartitioningII.Solution2 solution2 = new PalindromePartitioningII.Solution2();

    @Test
    void test1() {
        assertEquals(1, solution1.minCut("aab"));
    }

    @Test
    void test2() {
        assertEquals(1, solution2.minCut("aab"));
    }
}