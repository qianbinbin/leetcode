package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * <p>You are given two <b>non-empty</b> linked lists representing two non-negative integers. The digits are stored in <b>reverse order</b>, and each of their nodes contains a single digit. Add the two numbers and return the sum&nbsp;as a linked list.</p>
 *
 * <p>You may assume the two numbers do not contain any leading zero, except the number 0 itself.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg" style="width: 483px; height: 342px;">
 * <pre><strong>Input:</strong> l1 = [2,4,3], l2 = [5,6,4]
 * <strong>Output:</strong> [7,0,8]
 * <strong>Explanation:</strong> 342 + 465 = 807.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> l1 = [0], l2 = [0]
 * <strong>Output:</strong> [0]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * <strong>Output:</strong> [8,9,9,9,0,0,0,1]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in each linked list is in the range <code>[1, 100]</code>.</li>
 * 	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
 * 	<li>It is guaranteed that the list represents a number that does not have leading zeros.</li>
 * </ul>
 */
public class AddTwoNumbers {
    public static class Solution1 {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode dummy = new ListNode(), tail = dummy;
            int sum, carry = 0;
            for (; l1 != null && l2 != null; l1 = l1.next, l2 = l2.next) {
                sum = l1.val + l2.val + carry;
                carry = sum / 10;
                tail.next = new ListNode(sum % 10);
                tail = tail.next;
            }
            for (; l1 != null; l1 = l1.next) {
                sum = l1.val + carry;
                carry = sum / 10;
                tail.next = new ListNode(sum % 10);
                tail = tail.next;
            }
            for (; l2 != null; l2 = l2.next) {
                sum = l2.val + carry;
                carry = sum / 10;
                tail.next = new ListNode(sum % 10);
                tail = tail.next;
            }
            if (carry != 0)
                tail.next = new ListNode(carry);
            return dummy.next;
        }
    }
}
