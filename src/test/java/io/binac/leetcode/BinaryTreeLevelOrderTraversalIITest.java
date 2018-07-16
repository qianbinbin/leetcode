package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BinaryTreeLevelOrderTraversalIITest {
    private final BinaryTreeLevelOrderTraversalII.Solution1 solution1 = new BinaryTreeLevelOrderTraversalII.Solution1();

    @Test
    void test1() {
        List<List<Integer>> expected = Arrays.asList(
                Arrays.asList(15, 7),
                Arrays.asList(9, 20),
                Collections.singletonList(3)
        );
        assertEquals(expected, solution1.levelOrderBottom(Trees.asTree(3, 9, 20, null, null, 15, 7)));
    }
}