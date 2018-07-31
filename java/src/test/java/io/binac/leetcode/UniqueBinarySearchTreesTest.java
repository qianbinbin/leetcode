package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniqueBinarySearchTreesTest {
    private final UniqueBinarySearchTrees.Solution1 solution1 = new UniqueBinarySearchTrees.Solution1();

    private final UniqueBinarySearchTrees.Solution2 solution2 = new UniqueBinarySearchTrees.Solution2();

    @Test
    void test1() {
        assertEquals(5, solution1.numTrees(3));
    }

    @Test
    void test2() {
        assertEquals(5, solution2.numTrees(3));
    }
}