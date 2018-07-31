package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConstructBinaryTreeFromPreorderAndInorderTraversalTest {
    private final ConstructBinaryTreeFromPreorderAndInorderTraversal.Solution1 solution1 = new ConstructBinaryTreeFromPreorderAndInorderTraversal.Solution1();

    @Test
    void test1() {
        int preOrder[] = {3, 9, 20, 15, 7}, inOrder[] = {9, 3, 15, 20, 7};
        assertTrue(Trees.equals(Trees.asTree(3, 9, 20, null, null, 15, 7), solution1.buildTree(preOrder, inOrder)));
    }
}