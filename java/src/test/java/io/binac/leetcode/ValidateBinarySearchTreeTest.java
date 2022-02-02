package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidateBinarySearchTreeTest {
    private static final ValidateBinarySearchTree.Solution1 SOLUTION1 = new ValidateBinarySearchTree.Solution1();
    private static final ValidateBinarySearchTree.Solution2 SOLUTION2 = new ValidateBinarySearchTree.Solution2();
    private static final ValidateBinarySearchTree.Solution3 SOLUTION3 = new ValidateBinarySearchTree.Solution3();

    private final TreeNode ROOT1 = Trees.asTree(2, 1, 3);
    private final boolean EXPECTED1 = true;

    private final TreeNode ROOT2 = Trees.asTree(5, 1, 4, null, null, 3, 6);
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isValidBST(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.isValidBST(ROOT2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.isValidBST(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.isValidBST(ROOT2));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.isValidBST(ROOT1));
        assertEquals(EXPECTED2, SOLUTION3.isValidBST(ROOT2));
    }
}