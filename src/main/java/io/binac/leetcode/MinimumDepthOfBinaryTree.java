package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given a binary tree, find its minimum depth.
 * <p>
 * <p>The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
 * return its minimum depth = 2.
 */
public class MinimumDepthOfBinaryTree {
    public static class Solution1 {
        public int minDepth(TreeNode root) {
            if (root == null)
                return 0;
            if (root.left == null)
                return minDepth(root.right) + 1;
            if (root.right == null)
                return minDepth(root.left) + 1;
            return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
        }
    }
}
