package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.*;

/**
 * <p>Given the <code>root</code> of a binary tree, return <em>the inorder traversal of its nodes' values</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="width: 125px; height: 200px;">
 * <pre><strong>Input:</strong> root = [1,null,2,3]
 * <strong>Output:</strong> [1,3,2]
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
 * <strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?
 */
public class BinaryTreeInorderTraversal {
    public static class Solution1 {
        private void inorderTraversal(TreeNode root, List<Integer> result) {
            if (root == null) return;
            inorderTraversal(root.left, result);
            result.add(root.val);
            inorderTraversal(root.right, result);
        }

        public List<Integer> inorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            inorderTraversal(root, result);
            return result;
        }
    }

    public static class Solution2 {
        public List<Integer> inorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            Deque<TreeNode> stack = new ArrayDeque<>();
            TreeNode n = root;
            while (n != null || !stack.isEmpty()) {
                if (n != null) {
                    stack.push(n);
                    n = n.left;
                } else {
                    n = stack.pop();
                    result.add(n.val);
                    n = n.right;
                }
            }
            return result;
        }
    }
}
