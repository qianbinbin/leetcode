package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DistinctSubsequencesTest {
    private final DistinctSubsequences.Solution1 solution1 = new DistinctSubsequences.Solution1();

    @Test
    void test1() {
        assertEquals(3, solution1.numDistinct("rabbbit", "rabbit"));
        assertEquals(5, solution1.numDistinct("babgbag", "bag"));
    }
}