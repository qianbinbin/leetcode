package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * <p>Given two integer arrays <code>inorder</code> and <code>postorder</code> where <code>inorder</code> is the inorder traversal of a binary tree and <code>postorder</code> is the postorder traversal of the same tree, construct and return <em>the binary tree</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg" style="width: 277px; height: 302px;">
 * <pre><strong>Input:</strong> inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * <strong>Output:</strong> [3,9,20,null,null,15,7]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> inorder = [-1], postorder = [-1]
 * <strong>Output:</strong> [-1]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= inorder.length &lt;= 3000</code></li>
 * 	<li><code>postorder.length == inorder.length</code></li>
 * 	<li><code>-3000 &lt;= inorder[i], postorder[i] &lt;= 3000</code></li>
 * 	<li><code>inorder</code> and <code>postorder</code> consist of <strong>unique</strong> values.</li>
 * 	<li>Each value of <code>postorder</code> also appears in <code>inorder</code>.</li>
 * 	<li><code>inorder</code> is <strong>guaranteed</strong> to be the inorder traversal of the tree.</li>
 * 	<li><code>postorder</code> is <strong>guaranteed</strong> to be the postorder traversal of the tree.</li>
 * </ul>
 */
public class ConstructBinaryTreeFromInorderAndPostorderTraversal {
    public static class Solution1 {
        private TreeNode buildTree(int[] inOrder, int inPos, int[] postOrder, int postPos, int len) {
            if (len == 0)
                return null;

            final int rootVal = postOrder[postPos + len - 1];
            int post = inPos;
            for (int e = inPos + len; post < e && inOrder[post] != rootVal; ++post) ;
            final int left = post - inPos, right = len - left - 1;
            return new TreeNode(rootVal, buildTree(inOrder, inPos, postOrder, postPos, left), buildTree(inOrder, inPos + 1 + left, postOrder, postPos + left, right));
        }

        public TreeNode buildTree(int[] inorder, int[] postorder) {
            return buildTree(inorder, 0, postorder, 0, inorder.length);
        }
    }
}
