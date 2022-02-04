package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SymmetricTreeTest {
    private static final SymmetricTree.Solution1 SOLUTION1 = new SymmetricTree.Solution1();
    private static final SymmetricTree.Solution2 SOLUTION2 = new SymmetricTree.Solution2();

    private final TreeNode ROOT1 = Trees.asTree(1, 2, 2, 3, 4, 4, 3);
    private final boolean EXPECTED1 = true;

    private final TreeNode ROOT2 = Trees.asTree(1, 2, 2, null, 3, null, 3);
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isSymmetric(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.isSymmetric(ROOT2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.isSymmetric(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.isSymmetric(ROOT2));
    }
}