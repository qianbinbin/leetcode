package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeLevelOrderTraversalIITest {
    private final BinaryTreeLevelOrderTraversalII.Solution1 solution1 = new BinaryTreeLevelOrderTraversalII.Solution1();

    private final BinaryTreeLevelOrderTraversalII.Solution2 solution2 = new BinaryTreeLevelOrderTraversalII.Solution2();

    @Test
    void test1() {
        List<List<Integer>> expected = Arrays.asList(
                Arrays.asList(15, 7),
                Arrays.asList(9, 20),
                Collections.singletonList(3)
        );
        assertEquals(expected, solution1.levelOrderBottom(Trees.asTree(3, 9, 20, null, null, 15, 7)));
    }

    @Test
    void test2() {
        List<List<Integer>> expected = Arrays.asList(
                Arrays.asList(15, 7),
                Arrays.asList(9, 20),
                Collections.singletonList(3)
        );
        assertEquals(expected, solution2.levelOrderBottom(Trees.asTree(3, 9, 20, null, null, 15, 7)));
    }
}