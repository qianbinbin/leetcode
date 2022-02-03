package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>You are given the <code>root</code> of a binary search tree (BST), where the values of <strong>exactly</strong> two nodes of the tree were swapped by mistake. <em>Recover the tree without changing its structure</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg" style="width: 422px; height: 302px;">
 * <pre><strong>Input:</strong> root = [1,3,null,null,2]
 * <strong>Output:</strong> [3,1,null,null,2]
 * <strong>Explanation:</strong> 3 cannot be a left child of 1 because 3 &gt; 1. Swapping 1 and 3 makes the BST valid.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg" style="width: 581px; height: 302px;">
 * <pre><strong>Input:</strong> root = [3,1,4,null,null,2]
 * <strong>Output:</strong> [2,1,4,null,null,3]
 * <strong>Explanation:</strong> 2 cannot be in the right subtree of 3 because 2 &lt; 3. Swapping 2 and 3 makes the BST valid.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[2, 1000]</code>.</li>
 * 	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <strong>Follow up:</strong> A solution using <code>O(n)</code> space is pretty straight-forward. Could you devise a constant <code>O(1)</code> space solution?
 */
public class RecoverBinarySearchTree {
    public static class Solution1 {
        private void inOrder(TreeNode root, List<TreeNode> result) {
            if (root == null) return;
            inOrder(root.left, result);
            result.add(root);
            inOrder(root.right, result);
        }

        public void recoverTree(TreeNode root) {
            List<TreeNode> nodes = new ArrayList<>();
            inOrder(root, nodes);
            int i = 0, j = nodes.size() - 1;
            while (i < j && nodes.get(i).val < nodes.get(i + 1).val) ++i;
            while (j > i && nodes.get(j).val > nodes.get(j - 1).val) --j;
            int tmp = nodes.get(i).val;
            nodes.get(i).val = nodes.get(j).val;
            nodes.get(j).val = tmp;
        }
    }

    public static class Solution2 {
        private void inOrder(TreeNode root, TreeNode[] pre, TreeNode[] invalid1, TreeNode[] invalid2) {
            if (root == null) return;
            inOrder(root.left, pre, invalid1, invalid2);
            if (pre[0] != null && pre[0].val > root.val) {
                if (invalid1[0] == null)
                    invalid1[0] = pre[0];
                invalid2[0] = root;
            }
            pre[0] = root;
            inOrder(root.right, pre, invalid1, invalid2);
        }

        public void recoverTree(TreeNode root) {
            TreeNode[] pre = new TreeNode[1], invalid1 = new TreeNode[1], invalid2 = new TreeNode[1];
            inOrder(root, pre, invalid1, invalid2);
            int tmp = invalid1[0].val;
            invalid1[0].val = invalid2[0].val;
            invalid2[0].val = tmp;
        }
    }
}
