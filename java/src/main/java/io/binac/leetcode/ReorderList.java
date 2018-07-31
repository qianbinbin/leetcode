package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * <p>reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * <p>
 * <p>You may not modify the values in the list's nodes, only nodes itself may be changed.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Given 1->2->3->4, reorder it to 1->4->2->3.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 * </blockquote></pre>
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

            ListNode dummy = new ListNode(0);
            dummy.next = slow;
            ListNode p = slow.next;
            while (p != null) {
                slow.next = p.next;
                p.next = dummy.next;
                dummy.next = p;
                p = slow.next;
            }

            ListNode p1 = head, p2 = dummy.next;
            while (p1.next != slow) {
                dummy.next = p2.next;
                p2.next = p1.next;
                p1.next = p2;
                p1 = p2.next;
                p2 = dummy.next;
            }
            p1.next = dummy.next;
        }
    }
}
