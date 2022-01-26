package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>Given the <code>head</code> of a linked list and a value <code>x</code>, partition it such that all nodes <strong>less than</strong> <code>x</code> come before nodes <strong>greater than or equal</strong> to <code>x</code>.</p>
 *
 * <p>You should <strong>preserve</strong> the original relative order of the nodes in each of the two partitions.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/partition.jpg" style="width: 662px; height: 222px;">
 * <pre><strong>Input:</strong> head = [1,4,3,2,5,2], x = 3
 * <strong>Output:</strong> [1,2,2,4,3,5]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> head = [2,1], x = 2
 * <strong>Output:</strong> [1,2]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the list is in the range <code>[0, 200]</code>.</li>
 * 	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
 * 	<li><code>-200 &lt;= x &lt;= 200</code></li>
 * </ul>
 */
public class PartitionList {
    public static class Solution1 {
        public ListNode partition(ListNode head, int x) {
            ListNode dummy1 = new ListNode(0), tail1 = dummy1;
            ListNode dummy2 = new ListNode(0), tail2 = dummy2;
            for (ListNode p = head; p != null; p = p.next) {
                if (p.val < x)
                    tail1 = (tail1.next = p);
                else
                    tail2 = (tail2.next = p);
            }
            tail1.next = dummy2.next;
            tail2.next = null;
            return dummy1.next;
        }
    }
}
