package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>Given the <code>head</code> of a sorted linked list, <em>delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list</em>. Return <em>the linked list <strong>sorted</strong> as well</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg" style="width: 500px; height: 142px;">
 * <pre><strong>Input:</strong> head = [1,2,3,3,4,4,5]
 * <strong>Output:</strong> [1,2,5]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg" style="width: 500px; height: 205px;">
 * <pre><strong>Input:</strong> head = [1,1,1,2,3]
 * <strong>Output:</strong> [2,3]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the list is in the range <code>[0, 300]</code>.</li>
 * 	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
 * 	<li>The list is guaranteed to be <strong>sorted</strong> in ascending order.</li>
 * </ul>
 */
public class RemoveDuplicatesFromSortedListII {
    public static class Solution1 {
        public ListNode deleteDuplicates(ListNode head) {
            ListNode dummy = new ListNode(0), tail = dummy, p = head;
            int skip;
            while (p != null) {
                if (p.next != null && p.next.val == p.val) {
                    skip = p.val;
                    while (p != null && p.val == skip)
                        p = p.next;
                } else {
                    tail.next = p;
                    tail = p;
                    p = p.next;
                }
            }
            tail.next = null;
            return dummy.next;
        }
    }
}
