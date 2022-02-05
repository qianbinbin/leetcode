package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeZigzagLevelOrderTraversalTest {
    private static final BinaryTreeZigzagLevelOrderTraversal.Solution1 SOLUTION1 = new BinaryTreeZigzagLevelOrderTraversal.Solution1();
    private static final BinaryTreeZigzagLevelOrderTraversal.Solution2 SOLUTION2 = new BinaryTreeZigzagLevelOrderTraversal.Solution2();

    private final TreeNode ROOT1 = Trees.asTree(3, 9, 20, null, null, 15, 7);
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Collections.singletonList(3),
            Arrays.asList(20, 9),
            Arrays.asList(15, 7)
    );

    private final TreeNode ROOT2 = Trees.asTree(1);
    private final List<List<Integer>> EXPECTED2 = Collections.singletonList(Collections.singletonList(1));

    private final TreeNode ROOT3 = Trees.asTree();
    private final List<List<Integer>> EXPECTED3 = Collections.emptyList();


    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.zigzagLevelOrder(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.zigzagLevelOrder(ROOT2));
        assertEquals(EXPECTED3, SOLUTION1.zigzagLevelOrder(ROOT3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.zigzagLevelOrder(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.zigzagLevelOrder(ROOT2));
        assertEquals(EXPECTED3, SOLUTION2.zigzagLevelOrder(ROOT3));
    }
}