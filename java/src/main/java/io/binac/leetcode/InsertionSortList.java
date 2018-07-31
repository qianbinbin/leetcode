package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Sort a linked list using insertion sort.
 * <p>
 * <p>https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif
 * <p>A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
 * <p>With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 * <p>
 * <p>
 * <p>Algorithm of Insertion Sort:
 * <p>
 * <p>1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
 * <p>2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
 * <p>3. It repeats until no input elements remain.
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
public class InsertionSortList {
    public static class Solution1 {
        public ListNode insertionSortList(ListNode head) {
            if (head == null) return null;

            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode p = head.next, unsorted, pre = dummy;
            head.next = null;
            while (p != null) {
                while (pre.next != null && p.val > pre.next.val)
                    pre = pre.next;
                unsorted = p.next;
                p.next = pre.next;
                pre.next = p;
                p = unsorted;
                pre = dummy;
            }
            return dummy.next;
        }
    }
}
