package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreePreorderTraversalTest {

    private final BinaryTreePreorderTraversal.Solution1 solution1 = new BinaryTreePreorderTraversal.Solution1();

    private final TreeNode root = Trees.asTree(1, null, 2, 3);

    private final List<Integer> expected = Arrays.asList(1, 2, 3);

    @Test
    void test1() {
        assertEquals(expected, solution1.preorderTraversal(root));
    }
}