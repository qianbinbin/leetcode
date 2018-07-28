package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
 *     Output: [1,2,3]
 * </blockquote></pre>
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
}
