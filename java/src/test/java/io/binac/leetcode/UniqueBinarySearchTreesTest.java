package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniqueBinarySearchTreesTest {
    private static final UniqueBinarySearchTrees.Solution1 SOLUTION1 = new UniqueBinarySearchTrees.Solution1();
    private static final UniqueBinarySearchTrees.Solution2 SOLUTION2 = new UniqueBinarySearchTrees.Solution2();

    private final int N1 = 3, EXPECTED1 = 5;
    private final int N2 = 1, EXPECTED2 = 1;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.numTrees(N1));
        assertEquals(EXPECTED2, SOLUTION1.numTrees(N2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.numTrees(N1));
        assertEquals(EXPECTED2, SOLUTION2.numTrees(N2));
    }
}