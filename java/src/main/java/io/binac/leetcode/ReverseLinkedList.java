package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>Given the <code>head</code> of a singly linked list, reverse the list, and return <em>the reversed list</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg" style="width: 542px; height: 222px;">
 * <pre><strong>Input:</strong> head = [1,2,3,4,5]
 * <strong>Output:</strong> [5,4,3,2,1]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg" style="width: 182px; height: 222px;">
 * <pre><strong>Input:</strong> head = [1,2]
 * <strong>Output:</strong> [2,1]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> head = []
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
 * 	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong> A linked list can be reversed either iteratively or recursively. Could you implement both?</p>
 */
public class ReverseLinkedList {
    public static class Solution1 {
        public ListNode reverseList(ListNode head) {
            ListNode dummy = new ListNode();
            for (ListNode node = head, next; node != null; node = next) {
                next = node.next;
                node.next = dummy.next;
                dummy.next = node;
            }
            return dummy.next;
        }
    }

    public static class Solution2 {
        public ListNode reverseList(ListNode head) {
            if (head == null || head.next == null)
                return head;
            ListNode newHead = reverseList(head.next);
            head.next.next = head;
            head.next = null;
            return newHead;
        }
    }
}
