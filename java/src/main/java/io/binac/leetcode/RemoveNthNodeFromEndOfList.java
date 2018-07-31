package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Given linked list: 1->2->3->4->5, and n = 2.
 *
 *     After removing the second node from the end, the linked list becomes 1->2->3->5.
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>Given n will always be valid.
 * <p>
 * <p>Follow up:
 * <p>
 * <p>Could you do this in one pass?
 */
public class RemoveNthNodeFromEndOfList {
    public static class Solution1 {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            if (head == null)
                throw new IllegalArgumentException("head can't be null");
            if (n < 1)
                throw new IllegalArgumentException("n can't be less than 1");

            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode fast = dummy, slow = dummy;
            while (n >= 0 && fast != null) {
                fast = fast.next;
                --n;
            }
            if (n >= 0)
                throw new IllegalArgumentException("n is out of range");
            while (fast != null) {
                slow = slow.next;
                fast = fast.next;
            }
            slow.next = slow.next.next;
            return dummy.next;
        }
    }
}
