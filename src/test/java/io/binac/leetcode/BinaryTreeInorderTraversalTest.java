package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeInorderTraversalTest {
    private final BinaryTreeInorderTraversal.Solution1 solution1 = new BinaryTreeInorderTraversal.Solution1();

    @Test
    void test1() {
        TreeNode root = Trees.asTree(1, null, 2, 3);
        List<Integer> expected = Arrays.asList(1, 3, 2);
        assertEquals(expected, solution1.inorderTraversal(root));
    }
}