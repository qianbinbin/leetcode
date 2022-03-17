package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>Given the <code>head</code> of a linked list, return <em>the list after sorting it in <strong>ascending order</strong></em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg" style="width: 450px; height: 194px;">
 * <pre><strong>Input:</strong> head = [4,2,1,3]
 * <strong>Output:</strong> [1,2,3,4]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg" style="width: 550px; height: 184px;">
 * <pre><strong>Input:</strong> head = [-1,5,3,4,0]
 * <strong>Output:</strong> [-1,0,3,4,5]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> head = []
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the list is in the range <code>[0, 5 * 10<sup>4</sup>]</code>.</li>
 * 	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow up:</strong> Can you sort the linked list in <code>O(n logn)</code> time and <code>O(1)</code> memory (i.e. constant space)?</p>
 */
public class SortList {
    public static class Solution1 {
        private ListNode merge(ListNode head1, ListNode head2) {
            ListNode dummy = new ListNode(0), tail = dummy;
            while (head1 != null && head2 != null) {
                if (head1.val <= head2.val) {
                    tail = tail.next = head1;
                    head1 = head1.next;
                } else {
                    tail = tail.next = head2;
                    head2 = head2.next;
                }
            }
            tail.next = head1 != null ? head1 : head2;
            return dummy.next;
        }

        private ListNode mergeSort(ListNode head) {
            if (head == null || head.next == null) return head;

            ListNode dummy = new ListNode(0, head);
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
