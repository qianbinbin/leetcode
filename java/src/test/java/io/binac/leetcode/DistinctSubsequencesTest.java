package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DistinctSubsequencesTest {
    private static final DistinctSubsequences.Solution1 SOLUTION1 = new DistinctSubsequences.Solution1();

    private final String S1 = "rabbbit", T1 = "rabbit";
    private final int EXPECTED1 = 3;

    private final String S2 = "babgbag", T2 = "bag";
    private final int EXPECTED2 = 5;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.numDistinct(S1, T1));
        assertEquals(EXPECTED2, SOLUTION1.numDistinct(S2, T2));
    }
}