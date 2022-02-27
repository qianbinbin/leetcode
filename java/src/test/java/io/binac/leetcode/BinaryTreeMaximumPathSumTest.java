package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeMaximumPathSumTest {
    private static final BinaryTreeMaximumPathSum.Solution1 SOLUTION1 = new BinaryTreeMaximumPathSum.Solution1();

    private final TreeNode ROOT1 = Trees.asTree(1, 2, 3);
    private final int EXPECTED1 = 6;

    private final TreeNode ROOT2 = Trees.asTree(-10, 9, 20, null, null, 15, 7);
    private final int EXPECTED2 = 42;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.maxPathSum(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.maxPathSum(ROOT2));
    }
}