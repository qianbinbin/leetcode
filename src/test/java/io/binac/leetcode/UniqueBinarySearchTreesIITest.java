package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;
import java.util.stream.IntStream;

import static org.junit.jupiter.api.Assertions.*;

class UniqueBinarySearchTreesIITest {
    private final UniqueBinarySearchTreesII.Solution1 solution1 = new UniqueBinarySearchTreesII.Solution1();

    @Test
    void test1() {
        List<TreeNode> actual = solution1.generateTrees(3);
        List<TreeNode> expected = Arrays.asList(
                Trees.asTree(1, null, 2, null, 3),
                Trees.asTree(1, null, 3, 2),
                Trees.asTree(2, 1, 3),
                Trees.asTree(3, 1, null, null, 2),
                Trees.asTree(3, 2, null, 1)
        );
        assertEquals(actual.size(), expected.size());
        IntStream.range(0, actual.size()).forEach(i -> assertTrue(Trees.equals(actual.get(i), expected.get(i))));
    }
}