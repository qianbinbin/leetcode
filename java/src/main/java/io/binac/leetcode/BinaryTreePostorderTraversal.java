package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.*;

/**
 * <p>Given the <code>root</code> of a&nbsp;binary tree, return <em>the postorder traversal of its nodes' values</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg" style="width: 127px; height: 200px;">
 * <pre><strong>Input:</strong> root = [1,null,2,3]
 * <strong>Output:</strong> [3,2,1]
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
 * 	<li>The number of the nodes in the tree is in the range <code>[0, 100]</code>.</li>
 * 	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?
 */
public class BinaryTreePostorderTraversal {
    public static class Solution1 {
        private void postOrderTraversal(TreeNode root, List<Integer> result) {
            if (root == null) return;
            postOrderTraversal(root.left, result);
            postOrderTraversal(root.right, result);
            result.add(root.val);
        }

        public List<Integer> postorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            postOrderTraversal(root, result);
            return result;
        }
    }

    public static class Solution2 {
        public List<Integer> postorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            Deque<TreeNode> stack = new ArrayDeque<>();
            TreeNode node = root, pre = null;
            while (node != null || !stack.isEmpty()) {
                if (node != null) {
                    stack.push(node);
                    node = node.left;
                } else {
                    TreeNode parent = stack.peek();
                    if (parent.right != null && pre != parent.right) {
                        node = parent.right;
                    } else {
                        result.add(parent.val);
                        pre = stack.pop();
                    }
                }
            }
            return result;
        }
    }

    public static class Solution3 {
        public List<Integer> postorderTraversal(TreeNode root) {
            LinkedList<Integer> result = new LinkedList<>();
            if (root == null) return result;

            Deque<TreeNode> stack = new ArrayDeque<>();
            stack.push(root);
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                result.addFirst(node.val);
                if (node.left != null) stack.push(node.left);
                if (node.right != null) stack.push(node.right);
            }
            return result;
        }
    }
}
