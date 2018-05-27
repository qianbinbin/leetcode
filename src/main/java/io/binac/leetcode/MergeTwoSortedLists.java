package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: 1->2->4, 1->3->4
 *     Output: 1->1->2->3->4->4
 * </blockquote></pre>
 */
public class MergeTwoSortedLists {
    public static class Solution1 {
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            if (l1 == null) return l2;
            if (l2 == null) return l1;

            ListNode dummy = new ListNode(0);
            ListNode tail = dummy;
            while (l1 != null && l2 != null) {
                if (l1.val < l2.val) {
                    tail.next = l1;
                    tail = l1;
                    l1 = l1.next;
                } else {
                    tail.next = l2;
                    tail = l2;
                    l2 = l2.next;
                }
            }
            if (l1 != null) tail.next = l1;
            else tail.next = l2;
            return dummy.next;
        }
    }
}
