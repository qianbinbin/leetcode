package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BalancedBinaryTreeTest {
    private final BalancedBinaryTree.Solution1 solution1 = new BalancedBinaryTree.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isBalanced(Trees.asTree(3, 9, 20, null, null, 15, 7)));
        assertFalse(solution1.isBalanced(Trees.asTree(1, 2, 2, 3, 3, null, null, 4, 4)));
    }
}