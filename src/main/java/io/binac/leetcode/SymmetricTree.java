package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * <p>
 * <p>For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * <blockquote><pre>
 *         1
 *        / \
 *       2   2
 *      / \ / \
 *     3  4 4  3
 * </blockquote></pre>
 * But the following [1,2,2,null,3,null,3] is not:
 * <blockquote><pre>
 *         1
 *        / \
 *       2   2
 *        \   \
 *        3    3
 * </blockquote></pre>
 * Note:
 * <p>Bonus points if you could solve it both recursively and iteratively.
 */
public class SymmetricTree {
    public static class Solution1 {
        private boolean isSymmetric(TreeNode root1, TreeNode root2) {
            if (root1 == null && root2 == null) return true;
            if (root1 == null || root2 == null) return false;
            if (root1.val != root2.val) return false;
            return isSymmetric(root1.left, root2.right) && isSymmetric(root1.right, root2.left);
        }

        public boolean isSymmetric(TreeNode root) {
            if (root == null) return true;
            return isSymmetric(root.left, root.right);
        }
    }
}
