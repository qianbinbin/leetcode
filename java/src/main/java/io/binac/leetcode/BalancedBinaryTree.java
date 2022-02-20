package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * <p>Given a binary tree, determine if it is height-balanced.</p>
 *
 * <p>For this problem, a height-balanced binary tree is defined as:</p>
 *
 * <blockquote>
 * <p>a binary tree in which the left and right subtrees of <em>every</em> node differ in height by no more than 1.</p>
 * </blockquote>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg" style="width: 342px; height: 221px;">
 * <pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg" style="width: 452px; height: 301px;">
 * <pre><strong>Input:</strong> root = [1,2,2,3,3,null,null,4,4]
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> root = []
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[0, 5000]</code>.</li>
 * 	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
 * </ul>
 */
public class BalancedBinaryTree {
    public static class Solution1 {
        private int depth(TreeNode root) {
            if (root == null)
                return 0;
            int left = depth(root.left);
            if (left == -1)
                return -1;
            int right = depth(root.right);
            if (right == -1)
                return -1;
            if (Math.abs(left - right) > 1)
                return -1;
            return Math.max(left, right) + 1;
        }

        public boolean isBalanced(TreeNode root) {
            return depth(root) != -1;
        }
    }
}
