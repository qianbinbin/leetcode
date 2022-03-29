package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeRightSideViewTest {
    private static final BinaryTreeRightSideView.Solution1 SOLUTION1 = new BinaryTreeRightSideView.Solution1();
    private static final BinaryTreeRightSideView.Solution2 SOLUTION2 = new BinaryTreeRightSideView.Solution2();

    private final TreeNode ROOT1 = Trees.asTree(1, 2, 3, null, 5, null, 4);
    private final List<Integer> EXPECTED1 = Arrays.asList(1, 3, 4);

    private final TreeNode ROOT2 = Trees.asTree(1, null, 3);
    private final List<Integer> EXPECTED2 = Arrays.asList(1, 3);

    private final TreeNode ROOT3 = Trees.asTree();
    private final List<Integer> EXPECTED3 = Collections.emptyList();

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.rightSideView(ROOT1));
        assertEquals(EXPECTED2, SOLUTION1.rightSideView(ROOT2));
        assertEquals(EXPECTED3, SOLUTION1.rightSideView(ROOT3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.rightSideView(ROOT1));
        assertEquals(EXPECTED2, SOLUTION2.rightSideView(ROOT2));
        assertEquals(EXPECTED3, SOLUTION2.rightSideView(ROOT3));
    }
}