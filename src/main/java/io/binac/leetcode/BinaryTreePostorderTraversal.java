package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

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
}
