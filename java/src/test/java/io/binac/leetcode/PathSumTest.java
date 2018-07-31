package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PathSumTest {
    private final PathSum.Solution1 solution1 = new PathSum.Solution1();

    @Test
    void test1() {
        assertTrue(solution1.hasPathSum(Trees.asTree(5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1), 22));
    }
}