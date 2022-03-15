package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreePreorderTraversalTest {
    private static final BinaryTreePreorderTraversal.Solution1 SOLUTION1 = new BinaryTreePreorderTraversal.Solution1();
    private static final BinaryTreePreorderTraversal.Solution2 SOLUTION2 = new BinaryTreePreorderTraversal.Solution2();

    private final TreeNode ROOT1 = Trees.asTree(1, null, 2, 3);
    private final List<Integer> EXPECTED1 = Arrays.asList(1, 2, 3);

    private final TreeNode ROOT2 = Trees.asTree();
    private final List<Integer> EXPECTED2 = Collections.emptyList();

    private final TreeNode ROOT3 = Trees.asTree(1);
    private final List<Integer> EXPECTED3 = Collections.singletonList(1);

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.preorderTraversal(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.preorderTraversal(ROOT2));
        assertEquals(EXPECTED3, SOLUTION1.preorderTraversal(ROOT3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.preorderTraversal(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.preorderTraversal(ROOT2));
        assertEquals(EXPECTED3, SOLUTION2.preorderTraversal(ROOT3));
    }
}