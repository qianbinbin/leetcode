package io.binac.leetcode;

import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConvertSortedArrayToBinarySearchTreeTest {
    private final ConvertSortedArrayToBinarySearchTree.Solution1 solution1 = new ConvertSortedArrayToBinarySearchTree.Solution1();

    @Test
    void test1() {
        int nums[] = {-10, -3, 0, 5, 9};
        assertTrue(Trees.equals(Trees.asTree(0, -3, 9, -10, null, 5), solution1.sortedArrayToBST(nums)));
    }
}