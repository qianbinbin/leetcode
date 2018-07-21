package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given a non-empty binary tree, find the maximum path sum.
 * <p>
 * <p>For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [1,2,3]
 *
 *            1
 *           / \
 *          2   3
 *
 *     Output: 6
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [-10,9,20,null,null,15,7]
 *
 *        -10
 *        / \
 *       9  20
 *         /  \
 *        15   7
 *
 *     Output: 42
 * </blockquote></pre>
 */
public class BinaryTreeMaximumPathSum {
    public static class Solution1 {
        private int maxSinglePathSum(TreeNode root, int[] maxPathSum) {
            if (root == null) return 0;

            int left = Math.max(0, maxSinglePathSum(root.left, maxPathSum)),
                    right = Math.max(0, maxSinglePathSum(root.right, maxPathSum));

            maxPathSum[0] = Math.max(maxPathSum[0], root.val + left + right);

            return root.val + Math.max(left, right);
        }

        public int maxPathSum(TreeNode root) {
            int result[] = {root.val};
            maxSinglePathSum(root, result);
            return result[0];
        }
    }
}
