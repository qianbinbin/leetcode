package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * <p>
 * <p>Note:
 * <p>You may assume that duplicates do not exist in the tree.
 * <p>
 * <p>For example, given
 * <blockquote><pre>
 *     inorder = [9,3,15,20,7]
 *     postorder = [9,15,7,20,3]
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
public class ConstructBinaryTreeFromInorderAndPostorderTraversal {
    public static class Solution1 {
        private TreeNode buildTree(int[] inOrder, int inOffset, int[] postOrder, int postOffset, int len) {
            if (len == 0)
                return null;

            final int rootVal = postOrder[postOffset + len - 1];
            int index = inOffset;
            while (index < inOffset + len && inOrder[index] != rootVal) ++index;
            if (index >= inOffset + len)
                throw new IllegalArgumentException("can't build binary tree");
            final int left = index - inOffset, right = len - left - 1;
            TreeNode leftTree = buildTree(inOrder, inOffset, postOrder, postOffset, left);
            TreeNode rightTree = buildTree(inOrder, inOffset + 1 + left, postOrder, postOffset + left, right);
            TreeNode root = new TreeNode(rootVal);
            root.left = leftTree;
            root.right = rightTree;
            return root;
        }

        public TreeNode buildTree(int[] inorder, int[] postorder) {
            if (inorder.length != postorder.length)
                throw new IllegalArgumentException("can't build binary tree");
            return buildTree(inorder, 0, postorder, 0, inorder.length);
        }
    }
}
