package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given two binary trees, write a function to check if they are the same or not.
 * <p>
 * <p>Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:     1         1
 *               / \       / \
 *              2   3     2   3
 *
 *             [1,2,3],   [1,2,3]
 *
 *     Output: true
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:     1         1
 *               /           \
 *              2             2
 *
 *             [1,2],     [1,null,2]
 *
 *     Output: false
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input:     1         1
 *               / \       / \
 *              2   1     1   2
 *
 *             [1,2,1],   [1,1,2]
 *
 *     Output: false
 * </blockquote></pre>
 */
public class SameTree {
    public static class Solution1 {
        public boolean isSameTree(TreeNode p, TreeNode q) {
            if (p == q) return true;
            if (p == null || q == null) return false;
            return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        }
    }
}
