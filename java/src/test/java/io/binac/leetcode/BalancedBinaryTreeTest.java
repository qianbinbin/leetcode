package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BalancedBinaryTreeTest {
    private static final BalancedBinaryTree.Solution1 SOLUTION1 = new BalancedBinaryTree.Solution1();

    private final TreeNode ROOT1 = Trees.asTree(3, 9, 20, null, null, 15, 7);
    private final boolean EXPECTED1 = true;

    private final TreeNode ROOT2 = Trees.asTree(1, 2, 2, 3, 3, null, null, 4, 4);
    private final boolean EXPECTED2 = false;

    private final TreeNode ROOT3 = Trees.asTree();
    private final boolean EXPECTED3 = true;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isBalanced(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.isBalanced(ROOT2));
        assertEquals(EXPECTED3, SOLUTION1.isBalanced(ROOT3));
    }
}