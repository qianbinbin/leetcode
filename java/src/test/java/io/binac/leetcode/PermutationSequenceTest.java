package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PermutationSequenceTest {
    private static final PermutationSequence.Solution1 SOLUTION1 = new PermutationSequence.Solution1();

    private final int N1 = 3, K1 = 3;
    private final String EXPECTED1 = "213";

    private final int N2 = 4, K2 = 9;
    private final String EXPECTED2 = "2314";

    private final int N3 = 3, K3 = 1;
    private final String EXPECTED3 = "123";


    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.getPermutation(N1, K1));
        assertEquals(EXPECTED2, SOLUTION1.getPermutation(N2, K2));
        assertEquals(EXPECTED3, SOLUTION1.getPermutation(N3, K3));
    }
}