package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeInorderTraversalTest {
    private static final BinaryTreeInorderTraversal.Solution1 SOLUTION1 = new BinaryTreeInorderTraversal.Solution1();
    private static final BinaryTreeInorderTraversal.Solution2 SOLUTION2 = new BinaryTreeInorderTraversal.Solution2();

    private final TreeNode ROOT1 = Trees.asTree(1, null, 2, 3);
    private final List<Integer> EXPECTED1 = Arrays.asList(1, 3, 2);

    private final TreeNode ROOT2 = Trees.asTree();
    private final List<Integer> EXPECTED2 = Collections.emptyList();

    private final TreeNode ROOT3 = Trees.asTree(1);
    private final List<Integer> EXPECTED3 = Collections.singletonList(1);

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.inorderTraversal(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.inorderTraversal(ROOT2));
        assertEquals(EXPECTED3, SOLUTION1.inorderTraversal(ROOT3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.inorderTraversal(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.inorderTraversal(ROOT2));
        assertEquals(EXPECTED3, SOLUTION2.inorderTraversal(ROOT3));
    }
}