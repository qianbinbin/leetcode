package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RecoverBinarySearchTreeTest {
    private static final RecoverBinarySearchTree.Solution1 SOLUTION1 = new RecoverBinarySearchTree.Solution1();
    private static final RecoverBinarySearchTree.Solution2 SOLUTION2 = new RecoverBinarySearchTree.Solution2();

    private TreeNode getROOT1() {
        return Trees.asTree(1, 3, null, null, 2);
    }

    private final TreeNode EXPECTED1 = Trees.asTree(3, 1, null, null, 2);

    private TreeNode getROOT2() {
        return Trees.asTree(3, 1, 4, null, null, 2);
    }

    private final TreeNode EXPECTED2 = Trees.asTree(2, 1, 4, null, null, 3);

    @Test
    void test1() {
        TreeNode root1 = getROOT1();
        SOLUTION1.recoverTree(root1);
        assertTrue(Trees.equals(EXPECTED1, root1));

        TreeNode root2 = getROOT2();
        SOLUTION1.recoverTree(root2);
        assertTrue(Trees.equals(EXPECTED2, root2));
    }

    @Test
    void test2() {
        TreeNode root1 = getROOT1();
        SOLUTION2.recoverTree(root1);
        assertTrue(Trees.equals(EXPECTED1, root1));

        TreeNode root2 = getROOT2();
        SOLUTION2.recoverTree(root2);
        assertTrue(Trees.equals(EXPECTED2, root2));
    }
}