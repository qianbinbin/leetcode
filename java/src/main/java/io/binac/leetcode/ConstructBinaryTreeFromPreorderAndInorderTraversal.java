package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * <p>
 * <p>Note:
 * <p>You may assume that duplicates do not exist in the tree.
 * <p>
 * <p>For example, given
 * <blockquote><pre>
 *     preorder = [3,9,20,15,7]
 *     inorder = [9,3,15,20,7]
 * </blockquote></pre>
 * Return the following binary tree:
 * <blockquote><pre>
 *         3
 *        / \
 *       9  20
 *         /  \
 *        15   7
 * </blockquote></pre>
 */
public class ConstructBinaryTreeFromPreorderAndInorderTraversal {
    public static class Solution1 {
        private TreeNode buildTree(int[] preOrder, int preOffset, int[] inOrder, int inOffset, int len) {
            if (len == 0)
                return null;

            final int rootVal = preOrder[preOffset];
            int index = inOffset;
            while (index < inOffset + len && inOrder[index] != rootVal) ++index;
            if (index >= inOffset + len)
                throw new IllegalArgumentException("can't construct binary tree");
            final int left = index - inOffset, right = len - left - 1;
            TreeNode leftTree = buildTree(preOrder, preOffset + 1, inOrder, inOffset, left);
            TreeNode rightTree = buildTree(preOrder, preOffset + 1 + left, inOrder, index + 1, right);
            TreeNode root = new TreeNode(rootVal);
            root.left = leftTree;
            root.right = rightTree;
            return root;
        }

        public TreeNode buildTree(int[] preorder, int[] inorder) {
            if (preorder.length != inorder.length)
                throw new IllegalArgumentException("can't construct binary tree");
            return buildTree(preorder, 0, inorder, 0, preorder.length);
        }
    }
}
