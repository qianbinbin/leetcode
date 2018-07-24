package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SumRootToLeafNumbersTest {
    private final SumRootToLeafNumbers.Solution1 solution1 = new SumRootToLeafNumbers.Solution1();

    @Test
    void test1() {
        assertEquals(25, solution1.sumNumbers(Trees.asTree(1, 2, 3)));
        assertEquals(1026, solution1.sumNumbers(Trees.asTree(4, 9, 0, 5, 1)));
    }
}