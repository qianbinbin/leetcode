package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.IntStream;

import static org.junit.jupiter.api.Assertions.*;

class UniqueBinarySearchTreesIITest {
    private static final UniqueBinarySearchTreesII.Solution1 SOLUTION1 = new UniqueBinarySearchTreesII.Solution1();

    private final int N1 = 3;
    private final List<TreeNode> EXPECTED1 = Arrays.asList(
            Trees.asTree(1, null, 2, null, 3),
            Trees.asTree(1, null, 3, 2),
            Trees.asTree(2, 1, 3),
            Trees.asTree(3, 1, null, null, 2),
            Trees.asTree(3, 2, null, 1)
    );

    private final int N2 = 1;
    private final List<TreeNode> EXPECTED2 = Collections.singletonList(Trees.asTree(1));

    @Test
    void test1() {
        List<TreeNode> actual1 = SOLUTION1.generateTrees(N1);
        assertEquals(actual1.size(), EXPECTED1.size());
        IntStream.range(0, actual1.size()).forEach(i -> assertTrue(Trees.equals(actual1.get(i), EXPECTED1.get(i))));

        List<TreeNode> actual2 = SOLUTION1.generateTrees(N2);
        assertEquals(actual2.size(), EXPECTED2.size());
        IntStream.range(0, actual2.size()).forEach(i -> assertTrue(Trees.equals(actual2.get(i), EXPECTED2.get(i))));
    }
}