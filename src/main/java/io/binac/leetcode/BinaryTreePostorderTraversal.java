package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [1,null,2,3]
 *        1
 *         \
 *          2
 *         /
 *        3
 *
 *     Output: [3,2,1]
 * </blockquote></pre>
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
            Stack<TreeNode> stack = new Stack<>();
            TreeNode node = root, pre = null;
            while (node != null || !stack.empty()) {
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

            Stack<TreeNode> stack = new Stack<>();
            stack.push(root);
            while (!stack.empty()) {
                TreeNode node = stack.pop();
                if (node.left != null) stack.push(node.left);
                if (node.right != null) stack.push(node.right);
                result.addFirst(node.val);
            }
            return result;
        }
    }
}
