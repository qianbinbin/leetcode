package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>Given the <code>head</code> of a singly linked list, return <code>true</code> if it is a palindrome.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" style="width: 422px; height: 62px;">
 * <pre><strong>Input:</strong> head = [1,2,2,1]
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" style="width: 182px; height: 62px;">
 * <pre><strong>Input:</strong> head = [1,2]
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
 * 	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <strong>Follow up:</strong> Could you do it in <code>O(n)</code> time and <code>O(1)</code> space?
 */
public class PalindromeLinkedList {
    public static class Solution1 {
        private boolean isPalindrome(ListNode head, ListNode[] pre) {
            if (head == null)
                return true;
            boolean result = isPalindrome(head.next, pre) && head.val == pre[0].val;
            pre[0] = pre[0].next;
            return result;
        }

        public boolean isPalindrome(ListNode head) {
            return isPalindrome(head, new ListNode[]{head});
        }
    }
}
