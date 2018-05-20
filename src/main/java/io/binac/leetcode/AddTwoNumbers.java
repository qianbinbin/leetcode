package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * <p>
 * <p>You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * <p>
 * <p>Example
 * <blockquote><pre>
 *     Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *     Output: 7 -> 0 -> 8
 *     Explanation: 342 + 465 = 807.
 * </blockquote></pre>
 */
public class AddTwoNumbers {
    public static class Solution1 {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            if (l1 == null && l2 == null) return null;

            ListNode dummy = new ListNode(0);
            ListNode tail = dummy;
            int sum, carry = 0;
            while (l1 != null && l2 != null) {
                sum = l1.val + l2.val + carry;
                carry = sum / 10;
                tail.next = new ListNode(sum % 10);
                tail = tail.next;
                l1 = l1.next;
                l2 = l2.next;
            }
            while (l1 != null) {
                sum = l1.val + carry;
                carry = sum / 10;
                tail.next = new ListNode(sum % 10);
                tail = tail.next;
                l1 = l1.next;
            }
            while (l2 != null) {
                sum = l2.val + carry;
                carry = sum / 10;
                tail.next = new ListNode(sum % 10);
                tail = tail.next;
                l2 = l2.next;
            }
            if (carry > 0) {
                tail.next = new ListNode(carry);
            }
            return dummy.next;
        }
    }
}
