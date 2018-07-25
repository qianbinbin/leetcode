package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PalindromePartitioningIITest {
    private PalindromePartitioningII.Solution1 solution1 = new PalindromePartitioningII.Solution1();

    @Test
    void test1() {
        assertEquals(1, solution1.minCut("aab"));
    }
}