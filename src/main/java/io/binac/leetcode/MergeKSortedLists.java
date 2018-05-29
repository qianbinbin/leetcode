package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input:
 *     [
 *       1->4->5,
 *       1->3->4,
 *       2->6
 *     ]
 *     Output: 1->1->2->3->4->4->5->6
 * </blockquote></pre>
 */
public class MergeKSortedLists {
    public static class Solution1 {
        private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            ListNode dummy = new ListNode(0);
            ListNode tail = dummy;
            while (l1 != null && l2 != null) {
                if (l1.val < l2.val) {
                    tail.next = l1;
                    l1 = l1.next;
                } else {
                    tail.next = l2;
                    l2 = l2.next;
                }
                tail = tail.next;
            }
            if (l1 != null)
                tail.next = l1;
            else if (l2 != null)
                tail.next = l2;
            return dummy.next;
        }

        public ListNode mergeKLists(ListNode[] lists) {
            if (lists.length == 0)
                return null;

            for (int interval = 1; interval < lists.length; interval *= 2) {
                for (int i = 0; i + interval < lists.length; i += 2 * interval)
                    lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            return lists[0];
        }
    }
}
