package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidateBinarySearchTreeTest {
    private final ValidateBinarySearchTree.Solution1 solution1 = new ValidateBinarySearchTree.Solution1();

    private final ValidateBinarySearchTree.Solution2 solution2 = new ValidateBinarySearchTree.Solution2();

    @Test
    void test1() {
        assertTrue(solution1.isValidBST(Trees.asTree(2, 1, 3)));
        assertFalse(solution1.isValidBST(Trees.asTree(5, 1, 4, null, null, 3, 6)));
    }

    @Test
    void test2() {
        assertTrue(solution2.isValidBST(Trees.asTree(2, 1, 3)));
        assertFalse(solution2.isValidBST(Trees.asTree(5, 1, 4, null, null, 3, 6)));
    }
}