package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given a binary tree, flatten it to a linked list in-place.
 * <p>
 * <p>For example, given the following tree:
 * <blockquote><pre>
 *         1
 *        / \
 *       2   5
 *      / \   \
 *     3   4   6
 * </blockquote></pre>
 * The flattened tree should look like:
 * <blockquote><pre>
 *     1
 *      \
 *       2
 *        \
 *         3
 *          \
 *           4
 *            \
 *             5
 *              \
 *               6
 * </blockquote></pre>
 */
public class FlattenBinaryTreeToLinkedList {
    public static class Solution1 {
        private void flatten(TreeNode root, TreeNode[] pre) {
            if (root == null)
                return;
            if (pre[0] != null) {
                pre[0].left = null;
                pre[0].right = root;
            }
            pre[0] = root;
            final TreeNode right = root.right;
            flatten(root.left, pre);
            flatten(right, pre);
        }

        public void flatten(TreeNode root) {
            flatten(root, new TreeNode[1]);
        }
    }
}
