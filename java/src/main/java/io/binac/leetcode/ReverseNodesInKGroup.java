package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * <p>
 * <p>k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * <p>
 * <p>Example:
 * <p>
 * <p>Given this linked list: 1->2->3->4->5
 * <p>
 * <p>For k = 2, you should return: 2->1->4->3->5
 * <p>
 * <p>For k = 3, you should return: 3->2->1->4->5
 * <p>
 * <p>Note:
 * <p>
 * <p>Only constant extra memory is allowed.
 * <p>You may not alter the values in the list's nodes, only nodes itself may be changed.
 */
public class ReverseNodesInKGroup {
    public static class Solution1 {
        public ListNode reverseKGroup(ListNode head, int k) {
            if (head == null)
                return null;
            if (k < 1)
                throw new IllegalArgumentException("k can't be less than 1");
            if (k == 1)
                return head;

            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode pre = dummy, tail, p, barrier;
            int i;
            while (true) {
                barrier = pre.next;
                for (i = 0; i < k && barrier != null; ++i)
                    barrier = barrier.next;
                if (i < k)
                    break;
                tail = pre.next;
                p = tail.next;
                while (p != barrier) {
                    tail.next = p.next;
                    p.next = pre.next;
                    pre.next = p;
                    p = tail.next;
                }
                pre = tail;
            }
            return dummy.next;
        }
    }
}
