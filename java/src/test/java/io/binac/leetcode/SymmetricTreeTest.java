package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SymmetricTreeTest {
    private final SymmetricTree.Solution1 solution1 = new SymmetricTree.Solution1();

    private final SymmetricTree.Solution2 solution2 = new SymmetricTree.Solution2();

    @Test
    void test1() {
        assertTrue(solution1.isSymmetric(Trees.asTree(1, 2, 2, 3, 4, 4, 3)));
        assertFalse(solution1.isSymmetric(Trees.asTree(1, 2, 2, null, 3, null, 3)));
    }

    @Test
    void test2() {
        assertTrue(solution2.isSymmetric(Trees.asTree(1, 2, 2, 3, 4, 4, 3)));
        assertFalse(solution2.isSymmetric(Trees.asTree(1, 2, 2, null, 3, null, 3)));
    }
}