"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
"""

from .utils import ListNode


class Solution1:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        tail = dummy
        carry = 0
        while l1 and l2:
            v = l1.val + l2.val + carry
            tail.next = ListNode(v % 10)
            tail = tail.next
            carry = v // 10
            l1 = l1.next
            l2 = l2.next
        while l1:
            v = l1.val + carry
            tail.next = ListNode(v % 10)
            tail = tail.next
            carry = v // 10
            l1 = l1.next
        while l2:
            v = l2.val + carry
            tail.next = ListNode(v % 10)
            tail = tail.next
            carry = v // 10
            l2 = l2.next
        if carry:
            tail.next = ListNode(1)
        return dummy.next
