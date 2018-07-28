package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreePostorderTraversalTest {

    private final BinaryTreePostorderTraversal.Solution1 solution1 = new BinaryTreePostorderTraversal.Solution1();

    private final TreeNode root = Trees.asTree(1, null, 2, 3);

    private final List<Integer> expected = Arrays.asList(3, 2, 1);

    @Test
    void test1() {
        assertEquals(expected, solution1.postorderTraversal(root));
    }
}