package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SymmetricTreeTest {
    private final SymmetricTree.Solution1 solution1 = new SymmetricTree.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isSymmetric(Trees.asTree(1, 2, 2, 3, 4, 4, 3)));
        assertFalse(solution1.isSymmetric(Trees.asTree(1, 2, 2, null, 3, null, 3)));
    }
}