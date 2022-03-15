package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.*;

/**
 * <p>Given the <code>root</code> of a binary tree, return <em>the preorder traversal of its nodes' values</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="width: 125px; height: 200px;">
 * <pre><strong>Input:</strong> root = [1,null,2,3]
 * <strong>Output:</strong> [1,2,3]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> root = []
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> root = [1]
 * <strong>Output:</strong> [1]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
 * 	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?</p>
 */
public class BinaryTreePreorderTraversal {
    public static class Solution1 {
        private void preOrderTraversal(TreeNode root, List<Integer> result) {
            if (root == null) return;
            result.add(root.val);
            preOrderTraversal(root.left, result);
            preOrderTraversal(root.right, result);
        }

        public List<Integer> preorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            preOrderTraversal(root, result);
            return result;
        }
    }

    public static class Solution2 {
        public List<Integer> preorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            if (root == null) return result;

            Deque<TreeNode> stack = new ArrayDeque<>();
            stack.push(root);
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                result.add(node.val);
                if (node.right != null) stack.push(node.right);
                if (node.left != null) stack.push(node.left);
            }
            return result;
        }
    }
}
