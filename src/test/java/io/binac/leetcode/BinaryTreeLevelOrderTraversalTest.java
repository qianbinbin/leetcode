package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeLevelOrderTraversalTest {
    private final BinaryTreeLevelOrderTraversal.Solution1 solution1 = new BinaryTreeLevelOrderTraversal.Solution1();

    @Test
    void test1() {
        List<List<Integer>> expected = Arrays.asList(
                Collections.singletonList(3),
                Arrays.asList(9, 20),
                Arrays.asList(15, 7)
        );
        assertEquals(expected, solution1.levelOrder(Trees.asTree(3, 9, 20, null, null, 15, 7)));
    }
}