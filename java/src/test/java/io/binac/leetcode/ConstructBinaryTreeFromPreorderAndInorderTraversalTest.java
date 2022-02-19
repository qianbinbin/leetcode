package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConstructBinaryTreeFromPreorderAndInorderTraversalTest {
    private static final ConstructBinaryTreeFromPreorderAndInorderTraversal.Solution1 SOLUTION1 = new ConstructBinaryTreeFromPreorderAndInorderTraversal.Solution1();

    private final int[] PREORDER1 = {3, 9, 20, 15, 7}, INORDER1 = {9, 3, 15, 20, 7};
    private final TreeNode EXPECTED1 = Trees.asTree(3, 9, 20, null, null, 15, 7);

    private final int[] PREORDER2 = {-1}, INORDER2 = {-1};
    private final TreeNode EXPECTED2 = Trees.asTree(-1);

    @Test
    void test1() {
        assertTrue(Trees.equals(EXPECTED1, SOLUTION1.buildTree(PREORDER1, INORDER1)));
        assertTrue(Trees.equals(EXPECTED2, SOLUTION1.buildTree(PREORDER2, INORDER2)));
    }
}