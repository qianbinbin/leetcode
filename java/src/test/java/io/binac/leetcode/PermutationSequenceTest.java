package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PermutationSequenceTest {
    private final PermutationSequence.Solution1 solution1 = new PermutationSequence.Solution1();

    private final PermutationSequence.Solution2 solution2 = new PermutationSequence.Solution2();

    @Test
    void test1() {
        assertEquals("213", solution1.getPermutation(3, 3));
        assertEquals("2314", solution1.getPermutation(4, 9));
    }

    @Test
    void test2() {
        assertEquals("213", solution2.getPermutation(3, 3));
        assertEquals("2314", solution2.getPermutation(4, 9));
    }
}