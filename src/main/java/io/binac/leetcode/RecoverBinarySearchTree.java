package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * <p>
 * <p>Recover the tree without changing its structure.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [1,3,null,null,2]
 *
 *        1
 *       /
 *      3
 *       \
 *        2
 *
 *     Output: [3,1,null,null,2]
 *
 *        3
 *       /
 *      1
 *       \
 *        2
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [3,1,4,null,null,2]
 *
 *        3
 *       / \
 *      1   4
 *         /
 *        2
 *
 *     Output: [2,1,4,null,null,3]
 *
 *        2
 *       / \
 *      1   4
 *         /
 *        3
 * </blockquote></pre>
 * Follow up:
 * <p>
 * <p>A solution using O(n) space is pretty straight forward.
 * <p>Could you devise a constant space solution?
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
            while (i < nodes.size() - 1 && nodes.get(i).val < nodes.get(i + 1).val) ++i;
            while (j > 0 && nodes.get(j).val > nodes.get(j - 1).val) --j;
            if (i < nodes.size() - 1 && j > 0) {
                int tmp = nodes.get(i).val;
                nodes.get(i).val = nodes.get(j).val;
                nodes.get(j).val = tmp;
            }
        }
    }

    public static class Solution2 {
        private void inOrder(TreeNode root, TreeNode temp[]) {
            if (root == null) return;
            inOrder(root.left, temp);
            if (temp[0] != null && temp[0].val > root.val) {
                if (temp[1] == null)
                    temp[1] = temp[0];
                temp[2] = root;
            }
            temp[0] = root;
            inOrder(root.right, temp);
        }

        public void recoverTree(TreeNode root) {
            // Make it reentrant
            // [pre, invalid1, invalid2]
            TreeNode temp[] = new TreeNode[3];
            inOrder(root, temp);
            TreeNode invalid1 = temp[1], invalid2 = temp[2];
            if (invalid1 != null && invalid2 != null) {
                int tmp = invalid1.val;
                invalid1.val = invalid2.val;
                invalid2.val = tmp;
            }
        }
    }
}
