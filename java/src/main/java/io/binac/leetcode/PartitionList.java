package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * <p>
 * <p>You should preserve the original relative order of the nodes in each of the two partitions.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: head = 1->4->3->2->5->2, x = 3
 *     Output: 1->2->2->4->3->5
 * </blockquote></pre>
 */
public class PartitionList {
    public static class Solution1 {
        public ListNode partition(ListNode head, int x) {
            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode tail = dummy;
            while (tail.next != null && tail.next.val < x) tail = tail.next;
            ListNode pre = tail, p = tail.next;
            while (p != null) {
                if (p.val < x) {
                    pre.next = p.next;
                    p.next = tail.next;
                    tail.next = p;
                    tail = p;
                    p = pre.next;
                } else {
                    pre = p;
                    p = p.next;
                }
            }
            return dummy.next;
        }
    }
}
