package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FlattenBinaryTreeToLinkedListTest {
    private static final FlattenBinaryTreeToLinkedList.Solution1 SOLUTION1 = new FlattenBinaryTreeToLinkedList.Solution1();
    private static final FlattenBinaryTreeToLinkedList.Solution2 SOLUTION2 = new FlattenBinaryTreeToLinkedList.Solution2();

    private TreeNode getROOT1() {
        return Trees.asTree(1, 2, 5, 3, 4, null, 6);
    }

    private final TreeNode EXPECTED1 = Trees.asTree(1, null, 2, null, 3, null, 4, null, 5, null, 6);

    private TreeNode getROOT2() {
        return Trees.asTree();
    }

    private final TreeNode EXPECTED2 = Trees.asTree();

    private TreeNode getROOT3() {
        return Trees.asTree(0);
    }

    private final TreeNode EXPECTED3 = Trees.asTree(0);

    @Test
    void test1() {
        TreeNode root1 = getROOT1();
        SOLUTION1.flatten(root1);
        assertTrue(Trees.equals(EXPECTED1, root1));

        TreeNode root2 = getROOT2();
        SOLUTION1.flatten(root2);
        assertTrue(Trees.equals(EXPECTED2, root2));

        TreeNode root3 = getROOT3();
        SOLUTION1.flatten(root3);
        assertTrue(Trees.equals(EXPECTED3, root3));
    }

    @Test
    void test2() {
        TreeNode root1 = getROOT1();
        SOLUTION2.flatten(root1);
        assertTrue(Trees.equals(EXPECTED1, root1));

        TreeNode root2 = getROOT2();
        SOLUTION2.flatten(root2);
        assertTrue(Trees.equals(EXPECTED2, root2));

        TreeNode root3 = getROOT3();
        SOLUTION2.flatten(root3);
        assertTrue(Trees.equals(EXPECTED3, root3));
    }
}