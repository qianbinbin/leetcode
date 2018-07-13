package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RecoverBinarySearchTreeTest {
    private final RecoverBinarySearchTree.Solution1 solution1 = new RecoverBinarySearchTree.Solution1();

    @Test
    void test1() {
        TreeNode root1 = Trees.asTree(1, 3, null, null, 2);
        solution1.recoverTree(root1);
        TreeNode expected1 = Trees.asTree(3, 1, null, null, 2);
        assertTrue(Trees.equals(expected1, root1));

        TreeNode root2 = Trees.asTree(3, 1, 4, null, null, 2);
        solution1.recoverTree(root2);
        TreeNode expected2 = Trees.asTree(2, 1, 4, null, null, 3);
        assertTrue(Trees.equals(expected2, root2));
    }
}