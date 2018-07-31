package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinimumDepthOfBinaryTreeTest {
    private final MinimumDepthOfBinaryTree.Solution1 solution1 = new MinimumDepthOfBinaryTree.Solution1();

    @Test
    void test1() {
        assertEquals(2, solution1.minDepth(Trees.asTree(3, 9, 20, null, null, 15, 7)));
    }
}