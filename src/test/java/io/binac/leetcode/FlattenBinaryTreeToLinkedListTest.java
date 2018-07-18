package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FlattenBinaryTreeToLinkedListTest {
    private final FlattenBinaryTreeToLinkedList.Solution1 solution1 = new FlattenBinaryTreeToLinkedList.Solution1();

    @Test
    void test1() {
        TreeNode root = Trees.asTree(1, 2, 5, 3, 4, null, 6);
        solution1.flatten(root);
        TreeNode expected = Trees.asTree(1, null, 2, null, 3, null, 4, null, 5, null, 6);
        assertTrue(Trees.equals(expected, root));
    }
}