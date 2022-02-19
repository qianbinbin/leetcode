package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * <p>Given two integer arrays <code>preorder</code> and <code>inorder</code> where <code>preorder</code> is the preorder traversal of a binary tree and <code>inorder</code> is the inorder traversal of the same tree, construct and return <em>the binary tree</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg" style="width: 277px; height: 302px;">
 * <pre><strong>Input:</strong> preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * <strong>Output:</strong> [3,9,20,null,null,15,7]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> preorder = [-1], inorder = [-1]
 * <strong>Output:</strong> [-1]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= preorder.length &lt;= 3000</code></li>
 * 	<li><code>inorder.length == preorder.length</code></li>
 * 	<li><code>-3000 &lt;= preorder[i], inorder[i] &lt;= 3000</code></li>
 * 	<li><code>preorder</code> and <code>inorder</code> consist of <strong>unique</strong> values.</li>
 * 	<li>Each value of <code>inorder</code> also appears in <code>preorder</code>.</li>
 * 	<li><code>preorder</code> is <strong>guaranteed</strong> to be the preorder traversal of the tree.</li>
 * 	<li><code>inorder</code> is <strong>guaranteed</strong> to be the inorder traversal of the tree.</li>
 * </ul>
 */
public class ConstructBinaryTreeFromPreorderAndInorderTraversal {
    public static class Solution1 {
        private TreeNode buildTree(int[] preOrder, int prePos, int[] inOrder, int inPos, int len) {
            if (len == 0)
                return null;

            int pos = inPos;
            for (int e = inPos + len; pos < e && inOrder[pos] != preOrder[prePos]; ++pos) ;
            final int left = pos - inPos, right = len - left - 1;
            return new TreeNode(preOrder[prePos], buildTree(preOrder, prePos + 1, inOrder, inPos, left), buildTree(preOrder, prePos + 1 + left, inOrder, pos + 1, right));
        }

        public TreeNode buildTree(int[] preorder, int[] inorder) {
            return buildTree(preorder, 0, inorder, 0, preorder.length);
        }
    }
}
