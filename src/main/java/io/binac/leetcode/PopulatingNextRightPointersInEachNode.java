package io.binac.leetcode;

import io.binac.leetcode.util.TreeLinkNode;

/**
 * Given a binary tree
 * <blockquote><pre>
 *     struct TreeLinkNode {
 *       TreeLinkNode *left;
 *       TreeLinkNode *right;
 *       TreeLinkNode *next;
 *     }
 * </blockquote></pre>
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 * <p>
 * <p>Initially, all next pointers are set to NULL.
 * <p>
 * <p>Note:
 * <p>
 * <p>You may only use constant extra space.
 * <p>Recursive approach is fine, implicit stack space does not count as extra space for this problem.
 * <p>You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 * <p>
 * <p>Example:
 * <p>
 * <p>Given the following perfect binary tree,
 * <blockquote><pre>
 *          1
 *        /  \
 *       2    3
 *      / \  / \
 *     4  5  6  7
 * </blockquote></pre>
 * After calling your function, the tree should look like:
 * <blockquote><pre>
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \  / \
 *     4->5->6->7 -> NULL
 * </blockquote></pre>
 */
public class PopulatingNextRightPointersInEachNode {
    public static class Solution1 {
        public void connect(TreeLinkNode root) {
            if (root == null) return;

            TreeLinkNode pre, p = root, firstChild;
            while (p.left != null) {
                firstChild = p.left;
                while (p != null) {
                    p.left.next = p.right;
                    pre = p;
                    p = p.next;
                    if (p != null)
                        pre.right.next = p.left;
                }
                p = firstChild;
            }
        }
    }
}
