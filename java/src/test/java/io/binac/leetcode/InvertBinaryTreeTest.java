package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InvertBinaryTreeTest {
    private static final InvertBinaryTree.Solution1 SOLUTION1 = new InvertBinaryTree.Solution1();

    private TreeNode getROOT1() {
        return Trees.asTree(4, 2, 7, 1, 3, 6, 9);
    }

    private final TreeNode EXPECTED1 = Trees.asTree(4, 7, 2, 9, 6, 3, 1);

    private TreeNode getROOT2() {
        return Trees.asTree(2, 1, 3);
    }

    private final TreeNode EXPECTED2 = Trees.asTree(2, 3, 1);

    private TreeNode getROOT3() {
        return Trees.asTree();
    }

    private final TreeNode EXPECTED3 = Trees.asTree();

    @Test
    void test1() {
        assertTrue(Trees.equals(EXPECTED1, SOLUTION1.invertTree(getROOT1())));
        assertTrue(Trees.equals(EXPECTED2, SOLUTION1.invertTree(getROOT2())));
        assertTrue(Trees.equals(EXPECTED3, SOLUTION1.invertTree(getROOT3())));
    }
}