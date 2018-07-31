package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeMaximumPathSumTest {
    private final BinaryTreeMaximumPathSum.Solution1 solution1 = new BinaryTreeMaximumPathSum.Solution1();

    @Test
    void test1() {
        assertEquals(6, solution1.maxPathSum(Trees.asTree(1, 2, 3)));
        assertEquals(42, solution1.maxPathSum(Trees.asTree(-10, 9, 20, null, null, 15, 7)));
    }
}