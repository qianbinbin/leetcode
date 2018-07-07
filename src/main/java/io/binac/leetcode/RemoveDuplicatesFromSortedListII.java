package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 1->2->3->3->4->4->5
 *     Output: 1->2->5
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 1->1->1->2->3
 *     Output: 2->3
 * </blockquote></pre>
 */
public class RemoveDuplicatesFromSortedListII {
    public static class Solution1 {
        public ListNode deleteDuplicates(ListNode head) {
            ListNode dummy = new ListNode(0), tail = dummy, p = head;
            while (p != null) {
                if (p.next == null || p.next.val != p.val) {
                    tail.next = p;
                    tail = p;
                    p = p.next;
                } else {
                    int skip = p.val;
                    while (p != null && p.val == skip)
                        p = p.next;
                }
            }
            tail.next = null;
            return dummy.next;
        }
    }
}
