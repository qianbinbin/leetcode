package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConstructBinaryTreeFromInorderAndPostorderTraversalTest {
    private final ConstructBinaryTreeFromInorderAndPostorderTraversal.Solution1 solution1 = new ConstructBinaryTreeFromInorderAndPostorderTraversal.Solution1();

    @Test
    void test1() {
        int inorder[] = {9, 3, 15, 20, 7}, postorder[] = {9, 15, 7, 20, 3};
        assertTrue(Trees.equals(Trees.asTree(3, 9, 20, null, null, 15, 7), solution1.buildTree(inorder, postorder)));
    }
}