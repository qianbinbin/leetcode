package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinimumDepthOfBinaryTreeTest {
    private static final MinimumDepthOfBinaryTree.Solution1 SOLUTION1 = new MinimumDepthOfBinaryTree.Solution1();
    private static final MinimumDepthOfBinaryTree.Solution2 SOLUTION2 = new MinimumDepthOfBinaryTree.Solution2();

    private final TreeNode ROOT1 = Trees.asTree(3, 9, 20, null, null, 15, 7);
    private final int EXPECTED1 = 2;

    private final TreeNode ROOT2 = Trees.asTree(2, null, 3, null, 4, null, 5, null, 6);
    private final int EXPECTED2 = 5;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.minDepth(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.minDepth(ROOT2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.minDepth(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.minDepth(ROOT2));
    }
}