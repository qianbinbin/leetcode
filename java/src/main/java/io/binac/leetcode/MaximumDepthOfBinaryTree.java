package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * <p>Given the <code>root</code> of a binary tree, return <em>its maximum depth</em>.</p>
 *
 * <p>A binary tree's <strong>maximum depth</strong>&nbsp;is the number of nodes along the longest path from the root node down to the farthest leaf node.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg" style="width: 400px; height: 277px;">
 * <pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
 * <strong>Output:</strong> 3
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> root = [1,null,2]
 * <strong>Output:</strong> 2
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
 * 	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
 * </ul>
 */
public class MaximumDepthOfBinaryTree {
    public static class Solution1 {
        public int maxDepth(TreeNode root) {
            if (root == null) return 0;
            return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
        }
    }
}
