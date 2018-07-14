package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SameTreeTest {
    private final SameTree.Solution1 solution1 = new SameTree.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.isSameTree(Trees.asTree(1, 2, 3), Trees.asTree(1, 2, 3)));
        assertFalse(solution1.isSameTree(Trees.asTree(1, 2), Trees.asTree(1, null, 2)));
        assertFalse(solution1.isSameTree(Trees.asTree(1, 2, 1), Trees.asTree(1, 1, 2)));
    }
}