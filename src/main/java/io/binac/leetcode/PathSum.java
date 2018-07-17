package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 * <p>
 * <p>Note: A leaf is a node with no children.
 * <p>
 * <p>Example:
 * <p>
 * <p>Given the below binary tree and sum = 22,
 * <blockquote><pre>
 *           5
 *          / \
 *         4   8
 *        /   / \
 *       11  13  4
 *      /  \      \
 *     7    2      1
 * </blockquote></pre>
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */
public class PathSum {
    public static class Solution1 {
        private boolean hasPath(TreeNode root, int sum) {
            if (root == null) return sum == 0;
            if (root.left == null) return hasPath(root.right, sum - root.val);
            if (root.right == null) return hasPath(root.left, sum - root.val);
            return hasPath(root.left, sum - root.val) || hasPath(root.right, sum - root.val);
        }

        public boolean hasPathSum(TreeNode root, int sum) {
            if (root == null) return false; // dirty case
            return hasPath(root, sum);
        }
    }
}
