package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>Given a linked list, reverse the nodes of a linked list <em>k</em> at a time and return its modified list.</p>
 *
 * <p><em>k</em> is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of <em>k</em> then left-out nodes, in the end, should remain as it is.</p>
 *
 * <p><strong>Follow up:</strong></p>
 *
 * <ul>
 * 	<li>Could you solve the problem in <code>O(1)</code> extra memory space?</li>
 * 	<li>You may not alter the values in the list's nodes, only nodes itself may be changed.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg" style="width: 542px; height: 222px;">
 * <pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
 * <strong>Output:</strong> [2,1,4,3,5]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg" style="width: 542px; height: 222px;">
 * <pre><strong>Input:</strong> head = [1,2,3,4,5], k = 3
 * <strong>Output:</strong> [3,2,1,4,5]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> head = [1,2,3,4,5], k = 1
 * <strong>Output:</strong> [1,2,3,4,5]
 * </pre>
 *
 * <p><strong>Example 4:</strong></p>
 *
 * <pre><strong>Input:</strong> head = [1], k = 1
 * <strong>Output:</strong> [1]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the list&nbsp;is in the range <code>sz</code>.</li>
 * 	<li><code>1 &lt;= sz &lt;= 5000</code></li>
 * 	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
 * 	<li><code>1 &lt;= k &lt;= sz</code></li>
 * </ul>
 */
public class ReverseNodesInKGroup {
    public static class Solution1 {
        public ListNode reverseKGroup(ListNode head, int k) {
            ListNode dummy = new ListNode(0, head);
            ListNode tail = dummy, first, p, end;
            int i;
            while ((first = tail.next) != null) {
                end = first;
                for (i = 0; i < k && end != null; ++i)
                    end = end.next;
                if (i < k)
                    break;

                p = first.next;
                while (p != end) {
                    first.next = p.next;
                    p.next = tail.next;
                    tail.next = p;
                    p = first.next;
                }
                tail = first;
            }
            return dummy.next;
        }
    }
}
