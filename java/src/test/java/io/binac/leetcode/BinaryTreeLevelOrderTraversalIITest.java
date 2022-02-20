package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeLevelOrderTraversalIITest {
    private static final BinaryTreeLevelOrderTraversalII.Solution1 SOLUTION1 = new BinaryTreeLevelOrderTraversalII.Solution1();
    private static final BinaryTreeLevelOrderTraversalII.Solution2 SOLUTION2 = new BinaryTreeLevelOrderTraversalII.Solution2();

    private final TreeNode ROOT1 = Trees.asTree(3, 9, 20, null, null, 15, 7);
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Arrays.asList(15, 7),
            Arrays.asList(9, 20),
            Collections.singletonList(3)
    );

    private final TreeNode ROOT2 = Trees.asTree(1);
    private final List<List<Integer>> EXPECTED2 = Collections.singletonList(Collections.singletonList(1));

    private final TreeNode ROOT3 = Trees.asTree();
    private final List<List<Integer>> EXPECTED3 = Collections.emptyList();


    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.levelOrderBottom(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.levelOrderBottom(ROOT2));
        assertEquals(EXPECTED3, SOLUTION1.levelOrderBottom(ROOT3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.levelOrderBottom(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.levelOrderBottom(ROOT2));
        assertEquals(EXPECTED3, SOLUTION2.levelOrderBottom(ROOT3));
    }
}