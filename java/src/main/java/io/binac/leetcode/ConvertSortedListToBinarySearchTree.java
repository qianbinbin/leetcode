package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;
import io.binac.leetcode.util.TreeNode;

/**
 * <p>Given the <code>head</code> of a singly linked list where elements are <strong>sorted in ascending order</strong>, convert it to a height balanced BST.</p>
 *
 * <p>For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of <em>every</em> node never differ by more than 1.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/linked.jpg" style="width: 500px; height: 388px;">
 * <pre><strong>Input:</strong> head = [-10,-3,0,5,9]
 * <strong>Output:</strong> [0,-3,9,-10,null,5]
 * <strong>Explanation:</strong> One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> head = []
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in <code>head</code> is in the range <code>[0, 2 * 10<sup>4</sup>]</code>.</li>
 * 	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
 * </ul>
 */
public class ConvertSortedListToBinarySearchTree {
    public static class Solution1 {
        private TreeNode sortedListToBST(ListNode[] node, int from, int to) {
            if (from == to)
                return null;
            final int half = (from + to) >>> 1;
            TreeNode left = sortedListToBST(node, from, half);
            TreeNode root = new TreeNode(node[0].val);
            root.left = left;
            node[0] = node[0].next;
            root.right = sortedListToBST(node, half + 1, to);
            return root;
        }

        public TreeNode sortedListToBST(ListNode head) {
            int size = 0;
            for (ListNode p = head; p != null; p = p.next) ++size;
            return sortedListToBST(new ListNode[]{head}, 0, size);
        }
    }
}
