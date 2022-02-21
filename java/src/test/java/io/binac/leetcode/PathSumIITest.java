package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PathSumIITest {
    private static final PathSumII.Solution1 SOLUTION1 = new PathSumII.Solution1();

    private final TreeNode ROOT1 = Trees.asTree(5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1);
    private final int TARGETSUM1 = 22;
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Arrays.asList(5, 4, 11, 2),
            Arrays.asList(5, 8, 4, 5)
    );

    private final TreeNode ROOT2 = Trees.asTree(1, 2, 3);
    private final int TARGETSUM2 = 5;
    private final List<List<Integer>> EXPECTED2 = Collections.emptyList();

    private final TreeNode ROOT3 = Trees.asTree(1, 2);
    private final int TARGETSUM3 = 0;
    private final List<List<Integer>> EXPECTED3 = Collections.emptyList();

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.pathSum(ROOT1, TARGETSUM1));
        assertEquals(EXPECTED2, SOLUTION1.pathSum(ROOT2, TARGETSUM2));
        assertEquals(EXPECTED3, SOLUTION1.pathSum(ROOT3, TARGETSUM3));
    }
}