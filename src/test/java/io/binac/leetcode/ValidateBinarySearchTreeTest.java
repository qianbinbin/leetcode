package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidateBinarySearchTreeTest {
    private final ValidateBinarySearchTree.Solution1 solution1 = new ValidateBinarySearchTree.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isValidBST(Trees.asTree(2, 1, 3)));
        assertFalse(solution1.isValidBST(Trees.asTree(5, 1, 4, null, null, 3, 6)));
    }
}