package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PathSumTest {
    private static final PathSum.Solution1 SOLUTION1 = new PathSum.Solution1();

    private final TreeNode ROOT1 = Trees.asTree(5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1);
    private final int TARGETSUM1 = 22;
    private final boolean EXPECTED1 = true;

    private final TreeNode ROOT2 = Trees.asTree(1, 2, 3);
    private final int TARGETSUM2 = 5;
    private final boolean EXPECTED2 = false;

    private final TreeNode ROOT3 = Trees.asTree();
    private final int TARGETSUM3 = 0;
    private final boolean EXPECTED3 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.hasPathSum(ROOT1, TARGETSUM1));
        assertEquals(EXPECTED2, SOLUTION1.hasPathSum(ROOT2, TARGETSUM2));
        assertEquals(EXPECTED3, SOLUTION1.hasPathSum(ROOT3, TARGETSUM3));
    }
}