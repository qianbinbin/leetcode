package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>You are given the head of a singly linked-list. The list can be represented as:</p>
 *
 * <pre>L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
 * </pre>
 *
 * <p><em>Reorder the list to be on the following form:</em></p>
 *
 * <pre>L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …
 * </pre>
 *
 * <p>You may not modify the values in the list's nodes. Only nodes themselves may be changed.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg" style="width: 422px; height: 222px;">
 * <pre><strong>Input:</strong> head = [1,2,3,4]
 * <strong>Output:</strong> [1,4,2,3]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg" style="width: 542px; height: 222px;">
 * <pre><strong>Input:</strong> head = [1,2,3,4,5]
 * <strong>Output:</strong> [1,5,2,4,3]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the list is in the range <code>[1, 5 * 10<sup>4</sup>]</code>.</li>
 * 	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
 * </ul>
 */
public class ReorderList {
    public static class Solution1 {
        public void reorderList(ListNode head) {
            if (head == null) return;

            ListNode slow = head, fast = head;
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            }

            ListNode dummy = new ListNode(0, slow);
            ListNode p;
            while ((p = slow.next) != null) {
                slow.next = p.next;
                p.next = dummy.next;
                dummy.next = p;
            }

            ListNode p1 = head, p2 = dummy.next, tail = dummy;
            while (p1 != slow) {
                tail = tail.next = p1;
                p1 = p1.next;
                tail = tail.next = p2;
                p2 = p2.next;
            }
        }
    }
}
