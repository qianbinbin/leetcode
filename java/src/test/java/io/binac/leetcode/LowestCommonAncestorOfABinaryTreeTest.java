package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LowestCommonAncestorOfABinaryTreeTest {
    private static final LowestCommonAncestorOfABinaryTree.Solution1 SOLUTION1 = new LowestCommonAncestorOfABinaryTree.Solution1();
    private static final LowestCommonAncestorOfABinaryTree.Solution2 SOLUTION2 = new LowestCommonAncestorOfABinaryTree.Solution2();
    private static final LowestCommonAncestorOfABinaryTree.Solution3 SOLUTION3 = new LowestCommonAncestorOfABinaryTree.Solution3();
    private static final LowestCommonAncestorOfABinaryTree.Solution4 SOLUTION4 = new LowestCommonAncestorOfABinaryTree.Solution4();

    private final TreeNode ROOT1 = Trees.asTree(3, 5, 1, 6, 2, 0, 8, null, null, 7, 4);
    private final TreeNode P1 = ROOT1.left, Q1 = ROOT1.right;
    private final TreeNode EXPECTED1 = ROOT1;

    private final TreeNode ROOT2 = Trees.asTree(3, 5, 1, 6, 2, 0, 8, null, null, 7, 4);
    private final TreeNode P2 = ROOT2.left, Q2 = ROOT2.left.right.right;
    private final TreeNode EXPECTED2 = ROOT2.left;

    private final TreeNode ROOT3 = Trees.asTree(1, 2);
    private final TreeNode P3 = ROOT3, Q3 = ROOT3.left;
    private final TreeNode EXPECTED3 = ROOT3;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.lowestCommonAncestor(ROOT1, P1, Q1));
        assertEquals(EXPECTED2, SOLUTION1.lowestCommonAncestor(ROOT2, P2, Q2));
        assertEquals(EXPECTED3, SOLUTION1.lowestCommonAncestor(ROOT3, P3, Q3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.lowestCommonAncestor(ROOT1, P1, Q1));
        assertEquals(EXPECTED2, SOLUTION2.lowestCommonAncestor(ROOT2, P2, Q2));
        assertEquals(EXPECTED3, SOLUTION2.lowestCommonAncestor(ROOT3, P3, Q3));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.lowestCommonAncestor(ROOT1, P1, Q1));
        assertEquals(EXPECTED2, SOLUTION3.lowestCommonAncestor(ROOT2, P2, Q2));
        assertEquals(EXPECTED3, SOLUTION3.lowestCommonAncestor(ROOT3, P3, Q3));
    }

    @Test
    void test4() {
        assertEquals(EXPECTED1, SOLUTION4.lowestCommonAncestor(ROOT1, P1, Q1));
        assertEquals(EXPECTED2, SOLUTION4.lowestCommonAncestor(ROOT2, P2, Q2));
        assertEquals(EXPECTED3, SOLUTION4.lowestCommonAncestor(ROOT3, P3, Q3));
    }
}