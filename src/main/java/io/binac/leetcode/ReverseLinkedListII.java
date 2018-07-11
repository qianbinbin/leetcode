package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Reverse a linked list from position m to n. Do it in one-pass.
 * <p>
 * <p>Note: 1 ≤ m ≤ n ≤ length of list.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: 1->2->3->4->5->NULL, m = 2, n = 4
 *     Output: 1->4->3->2->5->NULL
 * </blockquote></pre>
 */
public class ReverseLinkedListII {
    public static class Solution1 {
        public ListNode reverseBetween(ListNode head, int m, int n) {
            if (m < 1 || m > n)
                throw new IllegalArgumentException();
            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode tail = dummy;
            for (int i = 1; i < m; ++i)
                tail = tail.next;
            ListNode first = tail.next, p = tail.next.next;
            for (int i = m; i < n; ++i) {
                first.next = p.next;
                p.next = tail.next;
                tail.next = p;
                p = first.next;
            }
            return dummy.next;
        }
    }
}
