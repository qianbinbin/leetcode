package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;
import io.binac.leetcode.util.TreeNode;

/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * <p>
 * <p>For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Given the sorted linked list: [-10,-3,0,5,9],
 *
 *     One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *
 *           0
 *          / \
 *        -3   9
 *        /   /
 *      -10  5
 * </blockquote></pre>
 */
public class ConvertSortedListToBinarySearchTree {
    public static class Solution1 {
        private TreeNode sortedListToBST(ListNode[] pNode, int start, int end) {
            if (start == end)
                return null;
            final int half = (start + end) >>> 1;
            TreeNode left = sortedListToBST(pNode, start, half);
            TreeNode root = new TreeNode(pNode[0].val);
            root.left = left;
            pNode[0] = pNode[0].next;
            root.right = sortedListToBST(pNode, half + 1, end);
            return root;
        }

        public TreeNode sortedListToBST(ListNode head) {
            int len = 0;
            for (ListNode p = head; p != null; p = p.next, ++len) ;
            ListNode pNode[] = {head};
            return sortedListToBST(pNode, 0, len);
        }
    }
}
