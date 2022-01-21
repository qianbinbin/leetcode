package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * <p>You are given an array of <code>k</code> linked-lists <code>lists</code>, each linked-list is sorted in ascending order.</p>
 *
 * <p><em>Merge all the linked-lists into one sorted linked-list and return it.</em></p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> lists = [[1,4,5],[1,3,4],[2,6]]
 * <strong>Output:</strong> [1,1,2,3,4,4,5,6]
 * <strong>Explanation:</strong> The linked-lists are:
 * [
 *   1-&gt;4-&gt;5,
 *   1-&gt;3-&gt;4,
 *   2-&gt;6
 * ]
 * merging them into one sorted list:
 * 1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> lists = []
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> lists = [[]]
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>k == lists.length</code></li>
 * 	<li><code>0 &lt;= k &lt;= 10^4</code></li>
 * 	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
 * 	<li><code>-10^4 &lt;= lists[i][j] &lt;= 10^4</code></li>
 * 	<li><code>lists[i]</code> is sorted in <strong>ascending order</strong>.</li>
 * 	<li>The sum of <code>lists[i].length</code> won't exceed <code>10^4</code>.</li>
 * </ul>
 */
public class MergeKSortedLists {
    public static class Solution1 {
        private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            ListNode dummy = new ListNode(), tail = dummy;
            while (l1 != null && l2 != null) {
                if (l1.val <= l2.val) {
                    tail.next = l1;
                    tail = l1;
                    l1 = l1.next;
                } else {
                    tail.next = l2;
                    tail = l2;
                    l2 = l2.next;
                }
            }
            tail.next = l1 != null ? l1 : l2;
            return dummy.next;
        }

        public ListNode mergeKLists(ListNode[] lists) {
            if (lists.length == 0)
                return null;

            for (int interval = 1, i, step; interval < lists.length; interval *= 2) {
                for (i = 0, step = interval * 2; i + interval < lists.length; i += step)
                    lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            return lists[0];
        }
    }

    public static class Solution2 {
        public ListNode mergeKLists(ListNode[] lists) {
            if (lists.length == 0)
                return null;

            Queue<ListNode> heap = new PriorityQueue<>(lists.length, Comparator.comparingInt(o -> o.val));
            for (ListNode node : lists)
                if (node != null)
                    heap.offer(node);

            ListNode dummy = new ListNode();
            ListNode tail = dummy;
            while (!heap.isEmpty()) {
                tail.next = heap.poll();
                tail = tail.next;
                if (tail.next != null)
                    heap.offer(tail.next);
            }
            return dummy.next;
        }
    }
}
