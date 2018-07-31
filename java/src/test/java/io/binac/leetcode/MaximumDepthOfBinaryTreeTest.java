package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumDepthOfBinaryTreeTest {
    private final MaximumDepthOfBinaryTree.Solution1 solution1 = new MaximumDepthOfBinaryTree.Solution1();

    @Test
    void test1() {
        assertEquals(3, solution1.maxDepth(Trees.asTree(3, 9, 20, null, null, 15, 7)));
    }
}