package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 1->1->2
 *     Output: 1->2
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 1->1->2->3->3
 *     Output: 1->2->3
 * </blockquote></pre>
 */
public class RemoveDuplicatesFromSortedList {
    public static class Solution1 {
        public ListNode deleteDuplicates(ListNode head) {
            if (head == null)
                return null;
            ListNode tail = head;
            for (ListNode p = head.next; p != null; p = p.next) {
                if (p.val != tail.val) {
                    tail.next = p;
                    tail = p;
                }
            }
            tail.next = null;
            return head;
        }
    }
}
