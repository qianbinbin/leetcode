package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreePostorderTraversalTest {
    private static final BinaryTreePostorderTraversal.Solution1 SOLUTION1 = new BinaryTreePostorderTraversal.Solution1();
    private static final BinaryTreePostorderTraversal.Solution2 SOLUTION2 = new BinaryTreePostorderTraversal.Solution2();
    private static final BinaryTreePostorderTraversal.Solution3 SOLUTION3 = new BinaryTreePostorderTraversal.Solution3();

    private final TreeNode ROOT1 = Trees.asTree(1, null, 2, 3);
    private final List<Integer> EXPECTED1 = Arrays.asList(3, 2, 1);

    private final TreeNode ROOT2 = Trees.asTree();
    private final List<Integer> EXPECTED2 = Collections.emptyList();

    private final TreeNode ROOT3 = Trees.asTree(1);
    private final List<Integer> EXPECTED3 = Collections.singletonList(1);

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.postorderTraversal(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.postorderTraversal(ROOT2));
        assertEquals(EXPECTED3, SOLUTION1.postorderTraversal(ROOT3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.postorderTraversal(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.postorderTraversal(ROOT2));
        assertEquals(EXPECTED3, SOLUTION2.postorderTraversal(ROOT3));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.postorderTraversal(ROOT1));
        assertEquals(EXPECTED2, SOLUTION3.postorderTraversal(ROOT2));
        assertEquals(EXPECTED3, SOLUTION3.postorderTraversal(ROOT3));
    }
}