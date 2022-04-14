package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class KthSmallestElementInABSTTest {
    private static final KthSmallestElementInABST.Solution1 SOLUTION1 = new KthSmallestElementInABST.Solution1();

    private final TreeNode ROOT1 = Trees.asTree(3, 1, 4, null, 2);
    private final int K1 = 1;
    private final int EXPECTED1 = 1;

    private final TreeNode ROOT2 = Trees.asTree(5, 3, 6, 2, 4, null, null, 1);
    private final int K2 = 3;
    private final int EXPECTED2 = 3;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.kthSmallest(ROOT1, K1));
        assertEquals(EXPECTED2, SOLUTION1.kthSmallest(ROOT2, K2));
    }
}