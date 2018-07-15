package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given a binary tree, find its maximum depth.
 * <p>
 * <p>The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * <p>
 * <p>Note: A leaf is a node with no children.
 * <p>
 * <p>Example:
 * <p>
 * <p>Given binary tree [3,9,20,null,null,15,7],
 * <blockquote><pre>
 *         3
 *        / \
 *       9  20
 *         /  \
 *        15   7
 * </blockquote></pre>
 * return its depth = 3.
 */
public class MaximumDepthOfBinaryTree {
    public static class Solution1 {
        public int maxDepth(TreeNode root) {
            if (root == null) return 0;
            return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
        }
    }
}
