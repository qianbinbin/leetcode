package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given a binary tree, determine if it is height-balanced.
 * <p>
 * <p>For this problem, a height-balanced binary tree is defined as:
 * <p>
 * <p>a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * <p>
 * <p>Example 1:
 * <p>
 * Given the following tree [3,9,20,null,null,15,7]:
 * <blockquote><pre>
 *         3
 *        / \
 *       9  20
 *         /  \
 *        15   7
 * </blockquote></pre>
 * Return true.
 * <p>
 * <p>Example 2:
 * <p>
 * <p>Given the following tree [1,2,2,3,3,null,null,4,4]:
 * <blockquote><pre>
 *            1
 *           / \
 *          2   2
 *         / \
 *        3   3
 *       / \
 *      4   4
 * </blockquote></pre>
 * Return false.
 */
public class BalancedBinaryTree {
    public static class Solution1 {
        private int depth(TreeNode root, boolean[] isBalanced) {
            if (root == null)
                return 0;
            int left = depth(root.left, isBalanced);
            int right = depth(root.right, isBalanced);
            if (Math.abs(left - right) > 1)
                isBalanced[0] = false;
            return Math.max(left, right) + 1;
        }

        public boolean isBalanced(TreeNode root) {
            boolean isBalanced[] = {true};
            depth(root, isBalanced);
            return isBalanced[0];
        }
    }
}
