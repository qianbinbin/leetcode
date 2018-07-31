package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.Stack;

/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * <p>
 * <p>Assume a BST is defined as follows:
 * <p>
 * <p>The left subtree of a node contains only nodes with keys less than the node's key.
 * <p>The right subtree of a node contains only nodes with keys greater than the node's key.
 * <p>Both the left and right subtrees must also be binary search trees.
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *         2
 *        / \
 *       1   3
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *         5
 *        / \
 *       1   4
 *          / \
 *         3   6
 *     Output: false
 *     Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
 *                  is 5 but its right child's value is 4.
 * </blockquote></pre>
 */
public class ValidateBinarySearchTree {
    public static class Solution1 {
        private boolean isValidBST(TreeNode root, TreeNode[] pre) {
            if (root == null) return true;
            if (!isValidBST(root.left, pre)) return false;
            if (pre[0] != null && pre[0].val >= root.val) return false;
            pre[0] = root;
            return isValidBST(root.right, pre);
        }

        public boolean isValidBST(TreeNode root) {
            return isValidBST(root, new TreeNode[1]);
        }
    }

    public static class Solution2 {
        public boolean isValidBST(TreeNode root) {
            if (root == null) return true;
            Stack<TreeNode> stack = new Stack<>();
            TreeNode n = root, pre = null;
            while (n != null || !stack.empty()) {
                if (n != null) {
                    stack.push(n);
                    n = n.left;
                } else {
                    n = stack.pop();
                    if (pre != null && pre.val >= n.val) return false;
                    pre = n;
                    n = n.right;
                }
            }
            return true;
        }
    }
}
