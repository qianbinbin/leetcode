package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
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
 *     Output: [1,3,2]
 * </blockquote></pre>
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
            if (root == null) return Collections.emptyList();

            List<Integer> result = new ArrayList<>();
            Stack<TreeNode> stack = new Stack<>();
            TreeNode n = root;
            while (n != null || !stack.empty()) {
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
