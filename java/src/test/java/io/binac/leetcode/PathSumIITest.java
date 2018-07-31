package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PathSumIITest {
    private final PathSumII.Solution1 solution1 = new PathSumII.Solution1();

    @Test
    void test1() {
        List<List<Integer>> expected = Arrays.asList(
                Arrays.asList(5, 4, 11, 2),
                Arrays.asList(5, 8, 4, 5)
        );
        assertEquals(expected, solution1.pathSum(Trees.asTree(5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1), 22));
    }
}