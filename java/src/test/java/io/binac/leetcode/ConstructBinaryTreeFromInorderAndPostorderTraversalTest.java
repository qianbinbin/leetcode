package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConstructBinaryTreeFromInorderAndPostorderTraversalTest {
    private static final ConstructBinaryTreeFromInorderAndPostorderTraversal.Solution1 SOLUTION1 = new ConstructBinaryTreeFromInorderAndPostorderTraversal.Solution1();

    private final int[] INORDER1 = {9, 3, 15, 20, 7}, POSTORDER1 = {9, 15, 7, 20, 3};
    private final TreeNode EXPECTED1 = Trees.asTree(3, 9, 20, null, null, 15, 7);

    private final int[] INORDER2 = {-1}, POSTORDER2 = {-1};
    private final TreeNode EXPECTED2 = Trees.asTree(-1);

    @Test
    void test1() {
        assertTrue(Trees.equals(EXPECTED1, SOLUTION1.buildTree(INORDER1, POSTORDER1)));
        assertTrue(Trees.equals(EXPECTED2, SOLUTION1.buildTree(INORDER2, POSTORDER2)));
    }
}