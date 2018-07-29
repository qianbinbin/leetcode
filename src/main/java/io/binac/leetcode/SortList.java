package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 4->2->1->3
 *     Output: 1->2->3->4
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: -1->5->3->4->0
 *     Output: -1->0->3->4->5
 * </blockquote></pre>
 */
public class SortList {
    public static class Solution1 {
        private ListNode merge(ListNode head1, ListNode head2) {
            ListNode dummy = new ListNode(0), tail = dummy;
            while (head1 != null && head2 != null) {
                if (head1.val < head2.val) {
                    tail.next = head1;
                    head1 = head1.next;
                } else {
                    tail.next = head2;
                    head2 = head2.next;
                }
                tail = tail.next;
            }
            if (head1 != null) tail.next = head1;
            else tail.next = head2;
            return dummy.next;
        }

        private ListNode mergeSort(ListNode head) {
            if (head == null || head.next == null) return head;

            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode slow = dummy, fast = head;
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            }
            ListNode head1 = dummy.next, head2 = slow.next;
            slow.next = null;
            head1 = mergeSort(head1);
            head2 = mergeSort(head2);
            return merge(head1, head2);
        }

        public ListNode sortList(ListNode head) {
            return mergeSort(head);
        }
    }
}
