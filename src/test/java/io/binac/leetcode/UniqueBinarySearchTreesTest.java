package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniqueBinarySearchTreesTest {
    private final UniqueBinarySearchTrees.Solution1 solution1 = new UniqueBinarySearchTrees.Solution1();

    @Test
    void test1() {
        assertEquals(5, solution1.numTrees(3));
    }
}