package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumDepthOfBinaryTreeTest {
    private static final MaximumDepthOfBinaryTree.Solution1 SOLUTION1 = new MaximumDepthOfBinaryTree.Solution1();

    private final TreeNode ROOT1 = Trees.asTree(3, 9, 20, null, null, 15, 7);
    private final int EXPECTED1 = 3;

    private final TreeNode ROOT2 = Trees.asTree(1, null, 2);
    private final int EXPECTED2 = 2;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maxDepth(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.maxDepth(ROOT2));
    }
}