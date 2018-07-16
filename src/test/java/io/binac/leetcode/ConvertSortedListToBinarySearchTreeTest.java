package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConvertSortedListToBinarySearchTreeTest {
    private final ConvertSortedListToBinarySearchTree.Solution1 solution1 = new ConvertSortedListToBinarySearchTree.Solution1();

    @Test
    void test1() {
        assertTrue(Trees.equals(Trees.asTree(0, -3, 9, -10, null, 5),
                solution1.sortedListToBST(LinkedLists.asLinkedList(-10, -3, 0, 5, 9))));
    }
}