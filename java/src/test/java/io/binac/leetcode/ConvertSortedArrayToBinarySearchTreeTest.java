package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConvertSortedArrayToBinarySearchTreeTest {
    private static final ConvertSortedArrayToBinarySearchTree.Solution1 SOLUTION1 = new ConvertSortedArrayToBinarySearchTree.Solution1();

    private final int[] NUMS1 = {-10, -3, 0, 5, 9};
    private final TreeNode EXPECTED1 = Trees.asTree(0, -3, 9, -10, null, 5);

    private final int[] NUMS2 = {1, 3};
    private final TreeNode EXPECTED2 = Trees.asTree(3, 1);


    @Test
    void test1() {
        assertTrue(Trees.equals(EXPECTED1, SOLUTION1.sortedArrayToBST(NUMS1)));
        assertTrue(Trees.equals(EXPECTED2, SOLUTION1.sortedArrayToBST(NUMS2)));
    }
}