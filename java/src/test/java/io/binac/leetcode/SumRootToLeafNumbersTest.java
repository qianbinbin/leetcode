package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SumRootToLeafNumbersTest {
    private static final SumRootToLeafNumbers.Solution1 SOLUTION1 = new SumRootToLeafNumbers.Solution1();

    private final TreeNode ROOT1 = Trees.asTree(1, 2, 3);
    private final int EXPECTED1 = 25;

    private final TreeNode ROOT2 = Trees.asTree(4, 9, 0, 5, 1);
    private final int EXPECTED2 = 1026;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.sumNumbers(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.sumNumbers(ROOT2));
    }
}