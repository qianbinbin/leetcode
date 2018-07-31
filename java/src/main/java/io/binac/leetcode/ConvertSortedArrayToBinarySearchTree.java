package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * <p>
 * <p>For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * <p>
 * Example:
 * <blockquote><pre>
 *     Given the sorted array: [-10,-3,0,5,9],
 *
 *     One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *
 *           0
 *          / \
 *        -3   9
 *        /   /
 *      -10  5
 * </blockquote></pre>
 */
public class ConvertSortedArrayToBinarySearchTree {
    public static class Solution1 {
        private TreeNode sortedArrayToBST(int[] sorted, int start, int end) {
            if (start == end)
                return null;
            int half = (start + end) >>> 1;
            TreeNode left = sortedArrayToBST(sorted, start, half);
            TreeNode right = sortedArrayToBST(sorted, half + 1, end);
            TreeNode root = new TreeNode(sorted[half]);
            root.left = left;
            root.right = right;
            return root;
        }

        public TreeNode sortedArrayToBST(int[] nums) {
            return sortedArrayToBST(nums, 0, nums.length);
        }
    }
}
