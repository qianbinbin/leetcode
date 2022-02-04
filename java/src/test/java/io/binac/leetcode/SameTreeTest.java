package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SameTreeTest {
    private static final SameTree.Solution1 SOLUTION1 = new SameTree.Solution1();

    private final TreeNode P1 = Trees.asTree(1, 2, 3), Q1 = Trees.asTree(1, 2, 3);
    private final boolean EXPECTED1 = true;

    private final TreeNode P2 = Trees.asTree(1, 2), Q2 = Trees.asTree(1, null, 2);
    private final boolean EXPECTED2 = false;

    private final TreeNode P3 = Trees.asTree(1, 2, 1), Q3 = Trees.asTree(1, 1, 2);
    private final boolean EXPECTED3 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isSameTree(P1, Q1));
        assertEquals(EXPECTED2, SOLUTION1.isSameTree(P2, Q2));
        assertEquals(EXPECTED3, SOLUTION1.isSameTree(P3, Q3));
    }
}