package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConvertSortedListToBinarySearchTreeTest {
    private static final ConvertSortedListToBinarySearchTree.Solution1 SOLUTION1 = new ConvertSortedListToBinarySearchTree.Solution1();

    private final ListNode HEAD1 = LinkedLists.asLinkedList(-10, -3, 0, 5, 9);
    private final TreeNode EXPECTED1 = Trees.asTree(0, -3, 9, -10, null, 5);

    private final ListNode HEAD2 = LinkedLists.asLinkedList();
    private final TreeNode EXPECTED2 = Trees.asTree();

    @Test
    void test1() {
        assertTrue(Trees.equals(EXPECTED1, SOLUTION1.sortedListToBST(HEAD1)));
        assertTrue(Trees.equals(EXPECTED2, SOLUTION1.sortedListToBST(HEAD2)));
    }
}