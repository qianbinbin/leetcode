package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Given 1->2->3->4, you should return the list as 2->1->4->3.
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>Your algorithm should use only constant extra space.
 * <p>You may not modify the values in the list's nodes, only nodes itself may be changed.
 */
public class SwapNodesInPairs {
    public static class Solution1 {
        public ListNode swapPairs(ListNode head) {
            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode pre = dummy, p = head;
            while (p != null && p.next != null) {
                pre.next = p.next;
                p.next = p.next.next;
                pre.next.next = p;
                pre = p;
                p = p.next;
            }
            return dummy.next;
        }
    }
}
