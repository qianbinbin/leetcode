package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Objects;

/**
 * <p>Given a binary tree, find its minimum depth.</p>
 *
 * <p>The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.</p>
 *
 * <p><strong>Note:</strong>&nbsp;A leaf is a node with no children.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg" style="width: 432px; height: 302px;">
 * <pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
 * <strong>Output:</strong> 2
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> root = [2,null,3,null,4,null,5,null,6]
 * <strong>Output:</strong> 5
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>5</sup>]</code>.</li>
 * 	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
 * </ul>
 */
public class MinimumDepthOfBinaryTree {
    public static class Solution1 {
        public int minDepth(TreeNode root) {
            if (root == null)
                return 0;
            int left = minDepth(root.left), right = minDepth(root.right);
            if (left == 0)
                return right + 1;
            if (right == 0)
                return left + 1;
            return Math.min(left, right) + 1;
        }
    }

    public static class Solution2 {
        public int minDepth(TreeNode root) {
            if (root == null)
                return 0;
            Deque<TreeNode> queue = new ArrayDeque<>();
            queue.offer(root);
            int level = 1;
            while (!queue.isEmpty()) {
                for (int i = queue.size(); i > 0; --i) {
                    TreeNode node = Objects.requireNonNull(queue.poll());
                    if (node.left == null && node.right == null)
                        return level;
                    if (node.left != null) queue.offer(node.left);
                    if (node.right != null) queue.offer(node.right);
                }
                ++level;
            }
            return level;
        }
    }
}
